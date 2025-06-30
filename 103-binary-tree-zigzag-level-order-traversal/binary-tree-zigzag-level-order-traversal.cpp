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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr) return {};
        queue<pair<TreeNode*, int>> q;
        vector<vector<int>> ans;
        q.push({root, 1});
        while(!q.empty()){
            int s = q.size();
            vector<int> temp;
            TreeNode* node;
            int lvl;
            for(int i = 0; i < s; i++){
                node = q.front().first;
                lvl = q.front().second;
                q.pop();
                if(node->left) q.push({node->left, lvl+1});
                if(node->right) q.push({node->right, lvl+1});
                temp.push_back(node->val);
            }
            if(lvl % 2 == 0){
                reverse(temp.begin(), temp.end());
                ans.push_back(temp);
            } 
            else ans.push_back(temp);
        }
        return ans;
    }
};