package leetcode31_40;

/**
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 Empty cells are indicated by the character '.'.
 You may assume that there will be only one unique solution.
 *
 * Created by DCLab on 11/20/2015.
 */
public class SudokuSolver {

    /**
     * 回溯法 TODO 注意此回溯法的特点
     * 和Valid Sudoku这题相比，此题中的输入是合法的。这样用回溯法我们只要检查新加入的值
     * 能否在行、列以及小方块里有效即可，没有必要检查整个矩阵。
     * http://www.cnblogs.com/panda_lin/archive/2013/11/04/sudoku_solver.html
     * @param board
     */
    public void solveSudoku(char[][] board) {
        dfs(board);
    }
    private boolean dfs(char[][] board){
        for (int r=0; r<9; ++r) {
            for (int c=0; c<9; ++c) {
                if (board[r][c]=='.'){
                    for (char ch='1'; ch<='9'; ch++){
                        board[r][c] = ch;
                        if (isValidSudoku(board, r, c)){    //限制条件
                            if (dfs(board)) return true;
                        }
                        board[r][c] = '.';
                    }
                    return false;
                }
            }
        }
        return true;
    }
    //TODO 注意如何计算所在3*3 block的起始行号/列号
    private boolean isValidSudoku(char[][] board, int x, int y) {   //x,y为坐标
        int r, c;
        for (r = 0; r<9; ++r) {   // Same value in the same c?
            if ((x!=r) && (board[r][y]==board[x][y])) return false;
        }
        for (c = 0; c<9; ++c) {   // Same value in the same r?
            if ((y!=c) && (board[x][c]==board[x][y])) return false;
        }
        for (r = (x/3)*3; r < (x/3+1)*3; ++r) {   // Same value in the 3 * 3 block it belong to?
            for (c = (y/3)*3; c < (y/3+1)*3; ++c) {
                if ((x!=r) && (y!=c) && (board[r][c]==board[x][y])) return false;
            }
        }
        return true;
    }

}
