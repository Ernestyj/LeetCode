
/**Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.
 A region is captured by flipping all 'O's into 'X's in that surrounded region.
 For example,
 X X X X
 X O O X
 X X O X
 X O X X
 After running your function, the board should be:
 X X X X
 X X X X
 X X X X
 X O X X
 * Created by eugene on 16/2/18.
 */
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty() || !board[0].size()) return;
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i) {// merge O's on left & right boarder
            dfs(board, i, 0);
            dfs(board, i, n-1);
        }
        for (int j = 0; j < n; ++j) {// merge O's on top & bottom boarder
            dfs(board, 0, j);
            dfs(board, m-1, j);
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if(board[i][j]=='O') board[i][j] = 'X';
                else if(board[i][j]=='#') board[i][j] = 'O';
            }
        }
    }
    void dfs(vector<vector<char>>& board, int x, int y){
        if(board[x][y]=='O'){
            board[x][y] = '#';
            if(x>1) dfs(board, x-1, y);
            if(y>1) dfs(board, x, y-1);
            if(x+1<board.size()) dfs(board, x+1, y);
            if(y+1<board[0].size()) dfs(board, x, y+1);
        }
    }
};
//public class SurroundedRegions {
//
//    /**
//     * http://www.programcreek.com/2014/04/leetcode-surrounded-regions-java/
//     * 边界处的O不能被包围,可以先遍历一次将与边界相连的所有O找出并替换成#,再遍历一次将O换成X,#换回O.
//     如果采用DFS可能会产生栈溢出,因此用BFS.
//     */
//    private Queue<Integer> queue = new LinkedList<>();
//    public void solve(char[][] board) {
//        if (board == null || board.length == 0) return;
//        int m = board.length, n = board[0].length;
//        for (int i = 0; i < m; i++) {// merge O's on left & right boarder
//            if (board[i][0] == 'O') bfsO(board, i, 0);
//            if (board[i][n - 1] == 'O') bfsO(board, i, n - 1);
//        }
//        for (int j = 0; j < n; j++) {// merge O's on top & bottom boarder
//            if (board[0][j] == 'O') bfsO(board, 0, j);
//            if (board[m - 1][j] == 'O') bfsO(board, m - 1, j);
//        }
//        for (int i = 0; i < m; i++) {// process the board
//            for (int j = 0; j < n; j++) {
//                if (board[i][j] == 'O') board[i][j] = 'X';
//                else if (board[i][j] == '#')  board[i][j] = 'O';//TODO 用else if
//            }
//        }
//    }
//    private void bfsO(char[][] board, int i, int j) {
//        int n = board[0].length;
//        processO(board, i, j);// fill current first and then its neighbors
//        while (!queue.isEmpty()) {
//            int k = queue.poll();
//            int x = k/n;
//            int y = k%n;
//            processO(board, x - 1, y);
//            processO(board, x + 1, y);
//            processO(board, x, y - 1);
//            processO(board, x, y + 1);
//        }
//    }
//    private void processO(char[][] board, int i, int j) {
//        int m = board.length, n = board[0].length;
//        if (i < 0 || i >= m || j < 0 || j >= n) return;
//        if (board[i][j]!='O') return;;
//        queue.offer(i * n + j);// add current cell in queue & then process its neighbors in bfsO
//        board[i][j] = '#';
//    }
//
//}
