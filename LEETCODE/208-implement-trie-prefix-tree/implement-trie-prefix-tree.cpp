class TrieNode{
    public : 
    TrieNode* children[26];
    bool isEnd;
    TrieNode(){
        isEnd = false;
        for(auto &i : children) i = NULL;
    }
};

class Trie {
public:
TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* current = root; 
        for(char ch : word){
            int index = ch - 'a';
            if(current->children[index] == NULL)
            current->children[index] = new TrieNode();

            current = current->children[index];

        }
        current->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for(char ch : word){
            int index = ch-'a';
            if(curr->children[index] == NULL) return false;
            curr = curr->children[index];
        }
        return curr->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(char ch : prefix){
            int index = ch-'a';
            if(curr->children[index] == NULL) return false;
            curr = curr->children[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */