package leetcode31_40;

import java.util.HashMap;

/**
 * Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
 The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
 *
 * Created by DCLab on 11/19/2015.
 */
public class ValidSudoku {

    public static void main(String[] args) {
        String[] input = {".87654321","2........","3........","4........","5........","6........","7........",
                "8........","9........"};
        char[][] in = new char[9][9];
        for (int i = 0; i < 9; i++) in[i] = input[i].toCharArray();

        System.out.println("*****RESULT*****");
        boolean result = new ValidSudoku().isValidSudoku(in);
        System.out.println(result);
    }

    // Brute force，对每个九宫格，行号起始block/3*3，列号起始block%3*3
    // 如果把九宫格按照行从0开始标号，那么数字board[i][j]位于第 i/3*3+j/3 个九宫格内
    // 时间复杂度：O(3*n^2), n=9
    public boolean isValidSudoku(char[][] board) {
        int len = board[0].length;
        HashMap<Character, Integer> map, book = new HashMap<>();
        for (char c = '1'; c <= '9'; c++) book.put(c, 0);
        for (int i = 0; i < len; i++){
            map = new HashMap<>();
            for (int j = 0; j < len; j++){
                if (board[i][j] == '.') continue;
                if (book.containsKey(board[i][j]) && !map.containsKey(board[i][j]))
                    map.put(board[i][j], 1);
                else return false;
            }
        }
        for (int i = 0; i < len; i++){
            map = new HashMap<>();
            for (int j = 0; j < len; j++){
                if (board[j][i] == '.') continue;
                if (book.containsKey(board[j][i]) && !map.containsKey(board[j][i]))
                    map.put(board[j][i], 1);
                else return false;
            }
        }
        for (int block = 0; block < 9; block++){
            map = new HashMap<>();
            for (int i = block/3*3; i < block/3*3 + 3; i++){
                for (int j = block%3*3; j < block%3*3 + 3; j++){
                    if (board[i][j] == '.') continue;
                    if (book.containsKey(board[i][j]) && !map.containsKey(board[i][j]))
                        map.put(board[i][j], 1);
                    else return false;
                }
            }
        }
        return true;
    }

}
