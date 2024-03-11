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
    void dfs(vector<string>& res, string cur, TreeNode* root){
      if(root == nullptr) return;
        if(root->left == nullptr && root->right == nullptr){
            cur += to_string(root->val);
            res.push_back(cur);
            cur.erase();
            return;
        }
        cur += to_string(root->val);
        cur += "->";
        
        if(root->left != nullptr) dfs(res, cur, root->left);
        if(root->right != nullptr) dfs(res, cur, root->right);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>res;
        string cur;
        dfs(res, cur, root);
        return res;
    }
};