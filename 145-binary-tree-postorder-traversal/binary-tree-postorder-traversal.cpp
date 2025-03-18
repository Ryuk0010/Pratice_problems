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
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return {};

        vector<int> result;
        stack<TreeNode*> stack;
        stack.push(root);

        while (!stack.empty()) {
            TreeNode* current = stack.top();
            stack.pop();
            result.push_back(current->val);

            if (current->left) {
                stack.push(current->left);
            }
            if (current->right) {
                stack.push(current->right);
            }
        }

        reverse(result.begin(), result.end());
        return result;
    }
};