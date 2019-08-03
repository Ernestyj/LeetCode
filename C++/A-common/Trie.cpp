
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
