package leetcode31_40;

/**
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 Empty cells are indicated by the character '.'.
 You may assume that there will be only one unique solution.
 *
 * Created by DCLab on 11/20/2015.
 */
public class SudokuSolver {

    public static void main(String[] args) {
        String[] input = {"..9748...","7........",".2.1.9...","..7...24.",".64.1.59.",".98...3..","...8.3.2.","........6","...2759.."};
        char[][] in = new char[9][9];
        for (int i = 0; i < 9; i++) in[i] = input[i].toCharArray();

        System.out.println("*****RESULT*****");
        new SudokuSolver().solveSudoku(in);
        for (int row = 0; row < 9; ++row) {
            for (int col = 0; col < 9; ++col) System.out.print(in[row][col] + " ");
            System.out.println();
        }
    }


    /**
     * 回溯法
     * 和Valid Sudoku这题相比，此题中的输入保证是有效的。这样用回溯法我们只要检查新加入的值
     * 能否在行、列以及小方块里有效即可，没有必要检查整个矩阵。
     * http://www.cnblogs.com/panda_lin/archive/2013/11/04/sudoku_solver.html
     * @param board
     */
    public void solveSudoku(char[][] board) {
        backTrackSolveSudoku(board);
    }
    private boolean backTrackSolveSudoku(char[][] board){
        for (int row = 0; row < 9; ++row) {
            for (int col = 0; col < 9; ++col) {

                if (board[row][col] == '.'){
                    for (char c = '1'; c <= '9'; c++){
                        board[row][col] = c;
                        if (isValidSudoku(board, row, col)){    //限制条件
                            if (backTrackSolveSudoku(board)) return true;
                        }
                        board[row][col] = '.';
                    }
                    return false;
                }

            }
        }
        return true;
    }
    //只要检查新加入的值能否在行、列以及小方块里有效即可，没有必要检查整个矩阵
    private boolean isValidSudoku(char[][] board, int x, int y) {   //x,y为坐标
        int row, col;
        // Same value in the same column?
        for (row = 0; row < 9; ++row) {
            if ((x != row) && (board[row][y] == board[x][y])) return false;
        }
        // Same value in the same row?
        for (col = 0; col < 9; ++col) {
            if ((y != col) && (board[x][col] == board[x][y])) return false;
        }
        // Same value in the 3 * 3 block it belong to?
        for (row = (x / 3) * 3; row < (x / 3 + 1) * 3; ++row) {
            for (col = (y / 3) * 3; col < (y / 3 + 1) * 3; ++col) {
                if ((x != row) && (y != col) && (board[row][col] == board[x][y])) return false;
            }
        }
        return true;
    }

}
