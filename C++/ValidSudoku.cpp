
/**
 * Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
 The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
 *
 * Created by DCLab on 11/19/2015.
 */
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

    }
};
//public class ValidSudoku {
//
//    //简洁,不易出错  https://leetcode.com/discuss/17990/sharing-my-easy-understand-java-solution-using-set
//    public boolean isValidSudoku(char[][] board) {
//        for (int i=0; i<9; i++) {
//            if (!partValid(board,i,0,i,8)) return false;    //每行
//            if (!partValid(board,0,i,8,i)) return false;    //每列
//        }
//        for (int i=0;i<3;i++){  //每3*3单元
//            for(int j=0;j<3;j++){
//                if (!partValid(board,i*3,j*3,i*3+2,j*3+2)) return false;
//            }
//        }
//        return true;
//    }
//    private boolean partValid(char[][] board, int x1, int y1, int x2, int y2){
//        HashSet set = new HashSet();
//        for (int i=x1; i<=x2; i++){
//            for (int j=y1; j<=y2; j++){
//                if (board[i][j]!='.') if(!set.add(board[i][j])) return false;
//            }
//        }
//        return true;
//    }
//
//    // Brute force，对每个九宫格，行号起始block/3*3，列号起始block%3*3
//    // 如果把九宫格按照行从0开始标号，那么数字board[i][j]位于第 i/3*3+j/3 个九宫格内
//    // 时间复杂度：O(3*n^2), n=9
//    public boolean isValidSudoku1(char[][] board) {
//        int len = board[0].length;
//        HashMap<Character, Integer> map, book = new HashMap<>();
//        for (char c = '1'; c <= '9'; c++) book.put(c, 0);
//        for (int i = 0; i < len; i++){
//            map = new HashMap<>();
//            for (int j = 0; j < len; j++){
//                if (board[i][j] == '.') continue;
//                if (book.containsKey(board[i][j]) && !map.containsKey(board[i][j]))
//                    map.put(board[i][j], 1);
//                else return false;
//            }
//        }
//        for (int i = 0; i < len; i++){
//            map = new HashMap<>();
//            for (int j = 0; j < len; j++){
//                if (board[j][i] == '.') continue;
//                if (book.containsKey(board[j][i]) && !map.containsKey(board[j][i]))
//                    map.put(board[j][i], 1);
//                else return false;
//            }
//        }
//        for (int block = 0; block < 9; block++){
//            map = new HashMap<>();
//            for (int i = block/3*3; i < block/3*3 + 3; i++){
//                for (int j = block%3*3; j < block%3*3 + 3; j++){
//                    if (board[i][j] == '.') continue;
//                    if (book.containsKey(board[i][j]) && !map.containsKey(board[i][j]))
//                        map.put(board[i][j], 1);
//                    else return false;
//                }
//            }
//        }
//        return true;
//    }
//
//}
