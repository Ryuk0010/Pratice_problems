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
    TreeNode* merge(TreeNode* root1, TreeNode* root2){
        // if(root1-> val == root2-> val) return TreeNode* root = new TreeNode(0);
        if(root1 == nullptr) return root2;
        if(root2 == nullptr) return root1;
        TreeNode* root = new TreeNode(root1->val + root2->val);
        // if(root1->left != nullptr || root2->left != nullptr){
            // root->val = (root1->val + root2->val);
            root->left = merge(root1->left, root2->left);
        // }
        // if(root1->right != nullptr || root2->right != nullptr){
            // root->val = (root1->val + root2->val);
            root->right = merge(root1->right, root2->right);
        // }
            
        return root;
    } 
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return merge(root1, root2);
    }
};