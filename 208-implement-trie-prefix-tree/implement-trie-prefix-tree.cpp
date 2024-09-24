class Trie {
    struct trieNode{
        bool end = false;
        trieNode* children[26];
    };
public:
    trieNode* root;
    trieNode* getNode(){
        trieNode* newNode = new trieNode();
        for(int i = 0; i < 26; i++) newNode->children[i] = NULL;
        newNode->end = false;
        return newNode;
    }
    Trie() {
        root = getNode();
    }
    
    void insert(string word) {
        trieNode* curr = root;
        for(int i = 0; i < word.length(); i++){
            char ch = word[i];
            int idx = ch - 'a';
            if(curr->children[idx] == NULL){
                curr->children[idx] = getNode();
            }
            curr = curr->children[idx];
        } 
        curr->end = true;

    }
    
    bool search(string word) {
        trieNode* curr = root;
        for(int i = 0; i < word.length(); i++){
            char ch = word[i];
            int idx = ch - 'a';
            if(curr->children[idx] == NULL) return false;
            curr = curr->children[idx]; 
        }
        if(curr->end == true) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        trieNode* curr = root;
        int i = 0;
        for(; i < prefix.length(); i++){
            char ch = prefix[i];
            int idx = ch - 'a';
            if(curr->children[idx] == NULL) return false;
            curr = curr->children[idx];
        }
        if(i == prefix.length()) return true;
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */