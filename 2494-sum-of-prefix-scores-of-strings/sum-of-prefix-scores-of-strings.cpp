class Solution {
public:
    struct TrieNode {
        map<char, TrieNode*> mp;
        int count;
    };
    
    void insert(TrieNode *root, string *str) {
        for (char ch: *str) {
            if (!root->mp[ch]) {
                struct TrieNode *node = new TrieNode;
                node->count = 0;
                root->mp[ch] = node;
            }
            
            root = root->mp[ch];
            root->count += 1;
        }
    }
    
    void count(vector<int> &vec, TrieNode *root, string *str) {
        int count = 0;

        for (char ch: *str) {
            count += root->mp[ch]->count;
            root = root->mp[ch];
        }
        
        vec.push_back(count);
    }
    
    vector<int> sumPrefixScores(vector<string>& words) {
        struct TrieNode *root = new TrieNode;
        vector<int> vec;
        
        for (string word: words) {
            insert(root, &word);
        }
        
        for (string word: words) {
            count(vec, root, &word);
        }
        
        return vec;
    }
};