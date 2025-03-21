/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == nullptr) return nullptr;
        if(root == p || root == q) return root;
        TreeNode* l = NULL;
        TreeNode* r = NULL;
        l = solve(root->left, p, q);
        r = solve(root->right, p, q);
        if(l == NULL) return r;
        if(r == NULL) return l;
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root, p, q);
    }
};