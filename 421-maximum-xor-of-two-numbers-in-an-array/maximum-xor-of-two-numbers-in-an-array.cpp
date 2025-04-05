class Solution {
public:
    struct trieNode {
        trieNode* left;
        trieNode* right;
    };
    
    void insert(trieNode* head, int& num) {
        trieNode* pCrawl = head;
        for(int i = 31; i>=0; i--) {
            int ith_bit = (num>>i)&1;
            if(ith_bit == 0) {
                if(!pCrawl->left) {
                    pCrawl->left = new trieNode();
                }
                pCrawl = pCrawl->left;
            } else {
                if(!pCrawl->right) {
                    pCrawl->right = new trieNode();
                }
                pCrawl = pCrawl->right;
            }
        }
    }
    
    int maxXor(trieNode* head, int &num) {
        int maxXor = 0;
        trieNode* pCrawl = head;
       
        for(int i = 31; i>=0; i--) {
            int ith_bit = (num>>i)&1;
           
            if(ith_bit == 1) {
                if(pCrawl->left) {
                    maxXor += pow(2, i)*1; 
                    pCrawl =  pCrawl->left;
                } else {
                    maxXor += pow(2, i)*0; 
                    pCrawl =  pCrawl->right;
                }
            } else {
                if(pCrawl->right) {
                    maxXor += pow(2, i)*1; 
                    pCrawl=  pCrawl->right;
                } else {
                    maxXor += pow(2, i)*0;
                    pCrawl=  pCrawl->left;
                }
            }
        }
        return maxXor;
    }
    
    int findMaximumXOR(vector<int>& nums) {
        trieNode* root = new trieNode();
        for(int &x: nums) {
            insert(root, x);
        }

        int result = 0;

        for(int &x : nums) {
            result = max(result, maxXor(root, x));
        }
        return result;
    }
};

