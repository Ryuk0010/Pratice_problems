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
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == NULL) return {};
        stack<TreeNode*> st;
        vector<int> ans;
        st.push(root);
        while(!st.empty()){
            auto t = st.top();
            st.pop();
            ans.push_back(t->val);
            if(t->right)st.push(t->right);
            if(t->left)st.push(t->left);
        }
        return ans;
    }
};