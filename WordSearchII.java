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

    /**http://www.programcreek.com/2014/06/leetcode-word-search-ii-java/
     * 若采用跟Word Search一样的思路,将超时.
     * 回溯中引入Trie,当前候选字符串不在所有单词的前缀中时,剪枝.
     * @param board
     * @param words
     * @return
     */
    private HashSet<String> result = new HashSet<>();   //防止重复的单词
    private int m, n;
    Trie trie;
    public List<String> findWords(char[][] board, String[] words) {
        trie = new Trie();
        for (String word: words) trie.insert(word);
        m = board.length;
        n = board[0].length;
        boolean[][] visited = new boolean[m][n];
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++)
                dfs(board, visited, "", i, j);
        }
        return new ArrayList<>(result);
    }
    private void dfs(char[][] board, boolean[][] visited, String str, int i, int j){
        if (i<0||j<0||i>=m||j>=n) return;
        if (visited[i][j]) return;
        str = str+board[i][j];
        if (!trie.startsWith(str)) return;  //剪枝
        if (trie.search(str)) result.add(str);
        visited[i][j] = true;
        dfs(board, visited, str, i-1, j);
        dfs(board, visited, str, i+1, j);
        dfs(board, visited, str, i, j-1);
        dfs(board, visited, str, i, j+1);
        visited[i][j] = false;
    }

}

//使用数组实现Trie
//Trie Node
class TrieNode{
    public TrieNode[] children = new TrieNode[26];
    public String item = "";
}
//Trie
class Trie{
    public TrieNode root = new TrieNode();

    public void insert(String word){
        TrieNode node = root;
        for(char c: word.toCharArray()){
            if(node.children[c-'a']==null){
                node.children[c-'a']= new TrieNode();
            }
            node = node.children[c-'a'];
        }
        node.item = word;
    }

    public boolean search(String word){
        TrieNode node = root;
        for(char c: word.toCharArray()){
            if(node.children[c-'a']==null) return false;
            node = node.children[c-'a'];
        }
        if(node.item.equals(word)){
            return true;
        }else{
            return false;
        }
    }

    public boolean startsWith(String prefix){
        TrieNode node = root;
        for(char c: prefix.toCharArray()){
            if(node.children[c-'a']==null) return false;
            node = node.children[c-'a'];
        }
        return true;
    }
}