struct trieNode {
    trieNode* children[26];
    bool isEndOfWord;
};

trieNode* getNode() {
    trieNode* newNode = new trieNode();
    newNode->isEndOfWord = false;
    for(int i = 0; i < 26; i++) {
        newNode->children[i] = NULL;
    }
    return newNode;
}

class Trie {
    public:
        trieNode* root;

        Trie() {
            root = getNode();
        }

        void insert(string word) {
            trieNode* pCrawl = root;
            for(int i = 0; i < word.length(); i++) {
                int idx = word[i] - 'a';
                if(pCrawl->children[idx] == NULL) {
                    pCrawl->children[idx] = getNode();
                }
                pCrawl = pCrawl->children[idx];
            }
            pCrawl->isEndOfWord = true;
        }

        bool searchPrefix(string prefix) {
            trieNode* pCrawl = root;
            for(int i = 0; i < prefix.length(); i++) {
                int idx = prefix[i] - 'a';
                if(pCrawl->children[idx] == NULL) {
                    return false;
                }
                pCrawl = pCrawl->children[idx];
            }

            return true;
        }
};

class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();

        int count = 0;

        for(int j = 0; j < n; j++) {
            Trie prefixTrie; //calls constrctor
            Trie suffixTrie; //calls constructor

            prefixTrie.insert(words[j]);
            string reversed = words[j];
            reverse(begin(reversed), end(reversed));

            suffixTrie.insert(reversed);

            for(int i = 0; i < j; i++) {
                if(words[i].length() > words[j].length()) {
                    continue;
                }

                string rev = words[i];
                reverse(begin(rev), end(rev));

                if(prefixTrie.searchPrefix(words[i]) == true && suffixTrie.searchPrefix(rev) == true) {
                    count++;
                }
            }
        }

        return count;
    }
};