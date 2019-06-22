
/**Given a 2d grid map of '1's (land) and '0's (water), count the number of islands.
 An island is surrounded by water and is formed by connecting adjacent lands
 horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
 * Created by eugene on 16/3/30.
 */
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {    //类似surrounded regions
        if(grid.empty()) return 0;
        int count = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if(grid[i][j]=='1'){
                    ++count;
                    dfs(grid, i, j);
                }else
                    grid[i][j]='X';
            }
        }
        return count;
    }
    void dfs(vector<vector<char>>& grid, int x, int y){
        if(grid[x][y]=='1'){
            grid[x][y] = 'X';
            if(x-1>=0) dfs(grid, x-1, y);
            if(y-1>=0) dfs(grid, x, y-1);
            if(x+1<grid.size()) dfs(grid, x+1, y);
            if(y+1<grid[0].size()) dfs(grid, x, y+1);   //TODO 注意不是y+1<grid.size()
        }
    }
};
//public class NumberOfIslands {
//
//    public int numIslands(char[][] grid) {
//        if (grid.length==0) return 0;
//        int count = 0;
//        for (int i=0; i<grid.length; i++){
//            for (int j=0; j<grid[0].length; j++){
//                if (grid[i][j]=='2') continue;
//                else if (grid[i][j]=='1') {
//                    count++;
//                    findAnIsland(grid, i, j);
//                } else grid[i][j] = '2'; //searched
//            }
//        }
//        return count;
//    }
//    private void findAnIsland(char[][] grid, int x, int y){
//        if (grid[x][y]!='1') return;
//        grid[x][y] = '2'; //searched
//        if (x-1>=0) findAnIsland(grid, x-1, y);    //上
//        if (x+1<grid.length) findAnIsland(grid, x+1, y);    //下
//        if (y-1>=0) findAnIsland(grid, x, y-1); //左
//        if (y+1<grid[0].length) findAnIsland(grid, x, y+1); //右
//    }
//
//}
