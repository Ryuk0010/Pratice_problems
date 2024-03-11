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
    int solve(TreeNode* root, int dir, int &ans){
      if(root->left == nullptr && root->right == nullptr && dir == 0) 
      return ans+=root->val;
      if(root->left != nullptr)solve(root->left, 0, ans);
      if(root->right != nullptr)solve(root->right, 1, ans);
      return ans;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int ans= 0;
        if(root->left == nullptr && root->right == nullptr) return 0;
        return solve(root, 0, ans);
    }
};