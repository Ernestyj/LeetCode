
/**
 * Given a 2D board and a word, find if the word exists in the grid.
 The word can be constructed from letters of sequentially adjacent cell,
 where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.
 For example,
 Given board =
 [ ['A','B','C','E'],
 ['S','F','C','S'],
 ['A','D','E','E'] ]
 word = "ABCCED", -> returns true,
 word = "SEE", -> returns true,
 word = "ABCB", -> returns false.
 * Created by DCLab on 12/31/2015.
 */
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(word.empty()) return true;
        if(board.empty() || board[0].empty()) return false;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if(dfs(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int start){
        if(start==word.size()) return true;
        else if(i<0 || j<0 || i>=board.size() || j>=board[0].size()) return false;
        else if(board[i][j]==word[start]){
            char temp = board[i][j];
            board[i][j] = '#';
            if(dfs(board, word, i+1, j, start+1)
                || dfs(board, word, i, j+1, start+1)
                || dfs(board, word, i-1, j, start+1)
                || dfs(board, word, i, j-1, start+1))
                return true;
            board[i][j] = temp;
            return false;
        } else return false;
    }
};
//public class WordSearch {
//
//    /**
//     * http://www.programcreek.com/2014/06/leetcode-word-search-java/
//     * 回溯法
//     * @param board
//     * @param word
//     * @return
//     */
//    public boolean exist(char[][] board, String word) {
//        for(int i=0; i<board.length; i++){
//            for(int j=0; j<board[0].length; j++){
//                if(dfs(board, word, i, j, 0)) return true;
//            }
//        }
//        return false;
//    }
//    private boolean dfs(char[][] board, String word, int i, int j, int k){
//        if(k==word.length()) return true;
//        if(i<0 || j<0 || i>=board.length || j>=board[0].length) return false;
//        if(board[i][j] == word.charAt(k)){
//            char temp = board[i][j];
//            board[i][j]='#';    //mark
//            if(dfs(board, word, i-1, j, k+1)
//                    ||dfs(board, word, i+1, j, k+1)
//                    ||dfs(board, word, i, j-1, k+1)
//                    ||dfs(board, word, i, j+1, k+1))
//                return true;
//            board[i][j]=temp;
//        }
//        return false;
//    }
//
//}
