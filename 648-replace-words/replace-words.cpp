class Solution {
public:
    class trieNode{
        public:
        trieNode *children[26];
        bool endofword;
        trieNode(){
            for (int i = 0; i < 26; i++) children[i] = nullptr;
            endofword = false;
        }
    };
    trieNode *root;

    void makeTrie(string str){
        trieNode *crl = root;
        for(int i = 0; i < str.length(); i++){
            int idx = str[i] - 'a';
            if(crl->children[idx] == NULL){
                crl->children[idx] = new trieNode();
            }
            crl = crl->children[idx];
        }
        crl->endofword = true;
    }

    string searchTrie(string str){
        trieNode *crl = root;
        string s = "";
        int i = 0;
        for(; i < str.length(); i++){
            int idx = str[i] - 'a';
            if(crl->children[idx] == NULL || crl->endofword==true){
                break;
            }
            else{
                s += str[i];
                crl = crl->children[idx];
            }
        }
        if(crl->endofword) return s;
        return str;

    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        stringstream ss(sentence);
        string word;
        vector<string> words;
        while(ss >> word){
            words.push_back(word);
        }
        root = new trieNode();
        for(int i = 0; i < dictionary.size(); i++){
            makeTrie(dictionary[i]);
        }
        string ans = "";
        for(int i = 0; i < words.size(); i++){
            string str = searchTrie(words[i]);
            ans.append(str);
            ans.append(" ");
        }
        ans.pop_back();
        return ans;
    }
};