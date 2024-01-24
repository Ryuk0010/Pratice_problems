/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int freq[10] = {0};
    int res = 0;
    int pseudoPalindromicPaths (TreeNode* root) {
        dfs(root);
        return res;
    }
    void  dfs(TreeNode* root){
      if(root == nullptr) return;
      freq[root->val]++;
      if(root->left == nullptr && root->right == nullptr){
        if(isPalindrom()) res++;

      }
      else{
        dfs(root->left);
        dfs(root->right);
      }
      freq[root->val]--;
    }
    bool isPalindrom(){
      int odd = 0;
      for(int i = 0; i < 10; i++){
        if(freq[i] % 2 != 0){
          odd++;
        }
      }
      if(odd > 1) return false;
      else return true;
    }
};