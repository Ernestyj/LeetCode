
/**Given a board with m by n cells, each cell has an initial state live (1) or dead (0).
 Each cell interacts with its eight neighbors (horizontal, vertical, diagonal)
 using the following four rules (taken from the above Wikipedia article):

 Any live cell with fewer than two live neighbors dies, as if caused by under-population.
 Any live cell with two or three live neighbors lives on to the next generation.
 Any live cell with more than three live neighbors dies, as if by over-population..
 Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
 Write a function to compute the next state (after one update) of the board given its current state.

 Follow up:
 Could you solve it in-place? Remember that the board needs to be updated at the same time:
 You cannot update some cells first and then use their updated values to update other cells.
 In this question, we represent the board using a 2D array. In principle, the board is infinite,
 which would cause problems when the active area encroaches the border of the array.
 How would you address these problems?
 * Created by eugene on 16/5/25.
 */
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> directions = {{1,-1},{1,0},{1,1},{0,-1},{0,1},{-1,-1},{-1,0},{-1,1}};
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int live = 0;
                for(auto& d: directions){   //统计[i][j]周围的live数量
                    if(i+d[0]<0 || i+d[0]>=m || j+d[1]<0 || j+d[1]>=n) continue;
                    else if(board[i+d[0]][j+d[1]]==1 || board[i+d[0]][j+d[1]]==2) ++live;
                }
                if(board[i][j]==1 && (live<2 || live>3)) board[i][j] = 2;
                else if(board[i][j]==0 && live==3) board[i][j] = 3;
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                board[i][j] %= 2;
            }
        }
    }
};
//public class GameOfLife {
//    /**注意如何引入预定义directions简化代码
//     * 注意如何设定状态机值
//     状态0： 死细胞转为死细胞
//     状态1： 活细胞转为活细胞 ==2live || ==3live
//     状态2： 活细胞转为死细胞 <2live || >3live
//     状态3： 死细胞转为活细胞 ==3live
//     最后我们对所有状态对2取余，那么状态0和2就变成死细胞，状态1和3就是活细胞.
//     */
//    int[][] directions ={{1,-1},{1,0},{1,1},{0,-1},{0,1},{-1,-1},{-1,0},{-1,1}};
//    public void gameOfLife(int[][] board) {
//        int m = board.length, n = board[0].length;
//        for(int i=0; i<m; i++){
//            for(int j=0; j<n; j++){
//                int live=0;
//                for(int[] d: directions){
//                    if(d[0]+i<0 || d[0]+i>=m || d[1]+j<0 || d[1]+j>=n) continue;
//                    if(board[d[0]+i][d[1]+j]==1 || board[d[0]+i][d[1]+j]==2) live++;
//                }
//                if(board[i][j]==0 && live==3) board[i][j]=3;
//                if(board[i][j]==1 && (live<2 || live>3)) board[i][j]=2;
//            }
//        }
//        for(int i=0;i<m;i++){
//            for(int j=0;j<n;j++){
//                board[i][j] %= 2;
//            }
//        }
//    }
//
//}
