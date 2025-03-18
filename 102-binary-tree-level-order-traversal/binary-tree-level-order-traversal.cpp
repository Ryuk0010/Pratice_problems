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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        q.push(root);
        while(!q.empty()){
            int s = q.size();
            vector<int> temp;
            for(int i = 0; i < s; i++){
                auto tp = q.front();
                q.pop();
                if(tp->left) q.push(tp->left);
                if(tp->right) q.push(tp->right);
                temp.push_back(tp->val);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};