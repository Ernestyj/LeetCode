
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
