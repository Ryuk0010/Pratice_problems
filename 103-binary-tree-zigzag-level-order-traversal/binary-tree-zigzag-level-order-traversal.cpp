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
    void solve(TreeNode* root, vector<vector<int>>& ans){
      queue<pair<TreeNode*, int>> q;
      q.push({root, 1});
      while(!q.empty()){
        int size = q.size();
        vector<int> temp(size, 0);
        int line = q.front().second;
        for(int i=0; i<size; i++){

          TreeNode *node = q.front().first;
          q.pop();
          if(line%2 != 0){
            temp[i] = node->val;
          }
          else{
            temp[size - i - 1] = node->val;
          }
          if(node->left)q.push({node->left, line+1});
            if(node->right)q.push({node->right, line+1});
        }
        ans.push_back(temp);
      }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

      vector<vector<int>> ans;
      if(!root) return ans;
      solve(root, ans);
      return ans;
    }
};