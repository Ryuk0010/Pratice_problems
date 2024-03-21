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
    void solve(TreeNode* root, vector<int> &ans, int line){
        if(root == nullptr) return;
        ans[line] = root->val;
        solve(root->left, ans, line+1);
        solve(root->right, ans, line+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans(101, -1);
        solve(root, ans, 0);
        vector<int> finalAns;
        for(int i = 0; i <= 100; i++){
          if(ans[i] != -1) finalAns.push_back(ans[i]);
        }
        return finalAns;
    }
};