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
    int ans;
    int solve(TreeNode* root){
        if(!root) return 0;

        int l = solve(root->left);
        int r = solve(root->right);

        int down = root->val + l + r;
        int oneSide = root->val + max(l, r);
        int currVal = root-> val;

        ans = max({down, oneSide, currVal, ans});

        return max(oneSide, currVal);
    }
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        solve(root);
        return ans;
    }
};