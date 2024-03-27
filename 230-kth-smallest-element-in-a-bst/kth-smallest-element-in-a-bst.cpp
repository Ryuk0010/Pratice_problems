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
    void solve(TreeNode* root, int k, int &ind, int &ans){
      if(!root) return;
      
      solve(root->left, k, ind, ans);
      ind++;
      if(ind == k){
        ans = root->val;
        return;
      }
      solve(root->right, k, ind, ans);

    }
    int kthSmallest(TreeNode* root, int k) {
      int ans = -1;
      int ind = 0;
      solve(root, k, ind, ans);
      return ans;

    }
};