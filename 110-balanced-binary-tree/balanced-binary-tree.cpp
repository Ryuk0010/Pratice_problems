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

    bool ans;
    int check(TreeNode *node){
        if(!node) return 0;
        int l = check(node->left);
        int r = check(node->right);

        if(abs(l-r) > 1) ans = false;
        return 1 + max(l, r);

    }
    bool isBalanced(TreeNode* root) {
        ans = true;
        check(root);
        return ans;
    }
};