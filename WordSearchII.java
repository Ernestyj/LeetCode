package leetcode211_220;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;

/**Given a 2D board and a list of words from the dictionary, find all words in the board.
 Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.
 For example,
 Given words = ["oath","pea","eat","rain"] and board =
 [
 ['o','a','a','n'],
 ['e','t','a','e'],
 ['i','h','k','r'],
 ['i','f','l','v']
 ]
 Return ["eat","oath"].
 Note: You may assume that all inputs are consist of lowercase letters a-z.
 * Created by eugene on 16/4/8.
 */
public class WordSearchII {

    /**
     * https://leetcode.com/discuss/77851/java-15ms-easiest-solution-100-00%25
     * 若采用跟Word Search一样的思路,将超时.
     * 回溯中引入Trie,当前候选字符串不在所有单词的前缀中时,剪枝.
     *
     * @param board
     * @param words
     * @return
     */
    public List<String> findWords(char[][] board, String[] words) {
        List<String> res = new ArrayList<>();
        TrieNode root = buildTrie(words);
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++)
                dfs(board, i, j, root, res);
        }
        return res;
    }

    public void dfs(char[][] board, int i, int j, TrieNode p, List<String> res) {
        if (i < 0 || j < 0 || i >= board.length || j >= board[0].length) return;
        char c = board[i][j];
        if (c == '#' || p.children[c - 'a'] == null) return;
        p = p.children[c - 'a'];
        if (p.word != null) {   // found one
            res.add(p.word);
            p.word = null;  // de-duplicate
        }
        board[i][j] = '#';
        dfs(board, i - 1, j, p, res);
        dfs(board, i, j - 1, p, res);
        dfs(board, i + 1, j, p, res);
        dfs(board, i, j + 1, p, res);
        board[i][j] = c;
    }

    class TrieNode {
        TrieNode[] children = new TrieNode[26];
        String word;
    }

    public TrieNode buildTrie(String[] words) {
        TrieNode root = new TrieNode();
        for (String w : words) {
            TrieNode node = root;
            for (char c : w.toCharArray()) {
                int i = c - 'a';
                if (node.children[i] == null) node.children[i] = new TrieNode();
                node = node.children[i];
            }
            node.word = w;
        }
        return root;
    }

}