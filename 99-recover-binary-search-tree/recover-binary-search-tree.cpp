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
    void solve(TreeNode* root, TreeNode* &first, TreeNode* &end, TreeNode* &prev){
        if(root == nullptr) return;
        solve(root->left, first, end, prev);
        if(prev){
            if(root->val < prev->val){
                if(!first) first = prev;
                end = root;
            }
        }
        prev = root;
        solve(root->right, first, end, prev);
    }
    void recoverTree(TreeNode* root) {
        TreeNode *first = nullptr;
        TreeNode *end = nullptr;
        TreeNode *prev = nullptr;
        solve(root, first, end, prev);
        swap(first->val, end->val);
    }
};