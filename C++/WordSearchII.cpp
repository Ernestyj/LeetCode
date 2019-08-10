
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
class Solution {
private:
    struct TrieNode {
        TrieNode *child[26];
        string str;
        TrieNode() : str("") {
            for (auto &a : child) a = nullptr;
        }
    };
    struct Trie {
        TrieNode *root;
        Trie() : root(new TrieNode()) {}
        void insert(string s) {
            TrieNode *p = root;
            for (auto &a : s) {
                int i = a - 'a';
                if (!p->child[i]) p->child[i] = new TrieNode();
                p = p->child[i];
            }
            p->str = s;
        }
        ~Trie(){
            delete root;
        }
    };
public:
    //若采用跟Word Search一样的思路,将超时. 回溯中引入Trie,当前候选字符串不在所有单词的前缀中时,剪枝.
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        if (words.empty() || board.empty() || board[0].empty()) return res;
        vector<vector<bool>> visit(board.size(), vector<bool>(board[0].size(), false));
        Trie trie;
        for (auto &a : words) trie.insert(a);
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (trie.root->child[board[i][j] - 'a']) {
                    dfs(board, trie.root->child[board[i][j] - 'a'], i, j, visit, res);
                }
            }
        }
        return res;
    }
    void dfs(vector<vector<char>>& board, TrieNode* p, int i, int j, vector<vector<bool>>& visit, vector<string>& res) {
        if (!p->str.empty()) {
            res.push_back(p->str);
            p->str.clear();//防止重复
        }
        int d[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        visit[i][j] = true;
        for (auto &a : d) {
            int nx = a[0] + i, ny = a[1] + j;
            if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size() && !visit[nx][ny] && p->child[board[nx][ny] - 'a']) {
                dfs(board, p->child[board[nx][ny] - 'a'], nx, ny, visit, res);
            }
        }
        visit[i][j] = false;
    }
};
//public class WordSearchII {
//    /**
//     * https://leetcode.com/discuss/77851/java-15ms-easiest-solution-100-00%25
//     * 若采用跟Word Search一样的思路,将超时.
//     * 回溯中引入Trie,当前候选字符串不在所有单词的前缀中时,剪枝.
//     */
//    public List<String> findWords(char[][] board, String[] words) {
//        List<String> res = new ArrayList<>();
//        TrieNode root = buildTrie(words);
//        for (int i = 0; i < board.length; i++) {
//            for (int j = 0; j < board[0].length; j++)
//                dfs(board, i, j, root, res);
//        }
//        return res;
//    }
//
//    public void dfs(char[][] board, int i, int j, TrieNode p, List<String> res) {
//        if (i < 0 || j < 0 || i >= board.length || j >= board[0].length) return;
//        char c = board[i][j];
//        if (c == '#' || p.children[c - 'a'] == null) return;
//        p = p.children[c - 'a'];
//        if (p.word != null) {   // found one
//            res.add(p.word);
//            p.word = null;  // de-duplicate
//        }
//        board[i][j] = '#';
//        dfs(board, i - 1, j, p, res);
//        dfs(board, i, j - 1, p, res);
//        dfs(board, i + 1, j, p, res);
//        dfs(board, i, j + 1, p, res);
//        board[i][j] = c;
//    }
//
//    class TrieNode {
//        TrieNode[] children = new TrieNode[26];
//        String word;
//    }
//
//    public TrieNode buildTrie(String[] words) {
//        TrieNode root = new TrieNode();
//        for (String w : words) {
//            TrieNode node = root;
//            for (char c : w.toCharArray()) {
//                int i = c - 'a';
//                if (node.children[i] == null) node.children[i] = new TrieNode();
//                node = node.children[i];
//            }
//            node.word = w;
//        }
//        return root;
//    }
//
//}