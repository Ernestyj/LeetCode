
class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    void insert(string word) {
        TrieNode* p = root;
        for (auto& c: word) {
            int i = c-'a';
            if(!p->child[i]) p->child[i] = new TrieNode();
            p = p->child[i];
        }
        p->isWord = true;
    }
    bool search(string word) {
        TrieNode* node = searchNode(word);
        return node && node->isWord;
    }
    bool startsWith(string prefix) {
        return searchNode(prefix) != nullptr;
    }
private:
    struct TrieNode{
        vector<TrieNode*> child;
        bool isWord;
        TrieNode(): isWord(false), child(vector<TrieNode*>(26, nullptr)){}
    };
    TrieNode* root;
    TrieNode* searchNode(string word){  //return TrieNode*
        TrieNode* p = root;
        for (auto& c: word) {
            int i = c-'a';
            if(!p->child[i]) return nullptr;
            p = p->child[i];
        }
        return p;
    }
};


/**Design a data structure that supports the following two operations:
 void addWord(word)
 bool search(word)
 search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.
 For example:
 addWord("bad")
 addWord("dad")
 addWord("mad")
 search("pad") -> false
 search("bad") -> true
 search(".ad") -> true
 search("b..") -> true
 Note:
 You may assume that all words are consist of lowercase letters a-z.
 * Created by eugene on 16/4/7.
 */
class WordDictionary {//与Implement Trie类似，除了search引入了"."匹配符需要用dfs
public:
    WordDictionary() {
        root = new TrieNode();
    }
    void addWord(string word) {
        TrieNode* p = root;
        for(auto& c: word){
            int i = c-'a';
            if(!p->child[i]) p->child[i] = new TrieNode();
            p = p->child[i];
        }
        p->isWord = true;
    }
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return searchDFS(word, root, 0);
    }
private:
    struct TrieNode{
        vector<TrieNode*> child;
        bool isWord;
        TrieNode(): isWord(false), child(vector<TrieNode*>(26, nullptr)){}
    };
    TrieNode* root;
    bool searchDFS(string word, TrieNode* p, int start){
        if(start==word.size()) return p->isWord;
        else{
            if(word[start]=='.'){
                for(auto& node: p->child){
                    if(node && searchDFS(word, node, start+1)) return true;
                }
                return false;
            }else{
                int i = word[start]-'a';
                return p->child[i] && searchDFS(word, p->child[i], start+1);
            }
        }
    }
};


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