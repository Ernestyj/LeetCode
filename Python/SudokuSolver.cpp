
/**
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 Empty cells are indicated by the character '.'.
 You may assume that there will be only one unique solution.
 *
 * Created by DCLab on 11/20/2015.
 */
class Solution {
public:
    //跟此题类似的有 Permutations 全排列，Combinations 组合项， N-Queens N皇后问题等等，其中尤其是跟 N-Queens N皇后问题的解题思路及其相似
    //对于每个需要填数字的格子带入1到9，每代入一个数字都判定其是否合法，如果合法就继续下一次递归，结束时把数字设回'.'
    void solveSudoku(vector<vector<char>>& board) {
        dfs(board);
    }
    bool dfs(vector<vector<char>>& board){
        for (int i=0; i<9; ++i) {
            for (int j=0; j<9; ++j) {
                if (board[i][j]=='.'){
                    for (char ch='1'; ch<='9'; ch++){
                        board[i][j] = ch;
                        if (isValidSudoku(board, i, j)){    //限制条件
                            if (dfs(board)) return true;
                        }
                        board[i][j] = '.';
                    }
                    return false;
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board, int x, int y) {   //x,y为坐标
        int i, j;
        for (i = 0; i<9; ++i) {   // Same value in the same i?
            if (x!=i && board[i][y]==board[x][y]) return false;
        }
        for (j = 0; j<9; ++j) {   // Same value in the same j?
            if (y!=j && board[x][j]==board[x][y]) return false;
        }
        //TODO 注意如何计算所在3*3 block的起始行号/列号
        for (i = (x/3)*3; i < (x/3+1)*3; ++i) {   // Same value in the 3 * 3 block it belong to?
            for (j = (y/3)*3; j < (y/3+1)*3; ++j) {
                if (x!=i && y!=j && board[i][j]==board[x][y]) return false;
            }
        }
        return true;
    }
};

//public class SudokuSolver {
//    /**
//     * 回溯法 TODO 注意此回溯法的特点
//     * 和Valid Sudoku这题相比，此题中的输入是合法的。这样用回溯法我们只要检查新加入的值
//     * 能否在行、列以及小方块里有效即可，没有必要检查整个矩阵。
//     * http://www.cnblogs.com/panda_lin/archive/2013/11/04/sudoku_solver.html
//     */
//    public void solveSudoku(char[][] board) {
//        dfs(board);
//    }
//    private boolean dfs(char[][] board){
//        for (int r=0; r<9; ++r) {
//            for (int c=0; c<9; ++c) {
//                if (board[r][c]=='.'){
//                    for (char ch='1'; ch<='9'; ch++){
//                        board[r][c] = ch;
//                        if (isValidSudoku(board, r, c)){    //限制条件
//                            if (dfs(board)) return true;
//                        }
//                        board[r][c] = '.';
//                    }
//                    return false;
//                }
//            }
//        }
//        return true;
//    }
//    //TODO 注意如何计算所在3*3 block的起始行号/列号
//    private boolean isValidSudoku(char[][] board, int x, int y) {   //x,y为坐标
//        int r, c;
//        for (r = 0; r<9; ++r) {   // Same value in the same c?
//            if ((x!=r) && (board[r][y]==board[x][y])) return false;
//        }
//        for (c = 0; c<9; ++c) {   // Same value in the same r?
//            if ((y!=c) && (board[x][c]==board[x][y])) return false;
//        }
//        for (r = (x/3)*3; r < (x/3+1)*3; ++r) {   // Same value in the 3 * 3 block it belong to?
//            for (c = (y/3)*3; c < (y/3+1)*3; ++c) {
//                if ((x!=r) && (y!=c) && (board[r][c]==board[x][y])) return false;
//            }
//        }
//        return true;
//    }
//
//}
