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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        int ans = 0;
        q.push({root, 0});
        while(!q.empty()){
            long long left = INT_MAX, right = INT_MIN;
            int size = q.size();
            for(int i = 0; i < size; i++){
                long long curr = q.front().second;
                TreeNode* temp = q.front().first;
                q.pop();
                left = min(curr, left);
                right = max(right, curr);
                if(temp -> left) q.push({temp -> left, curr*2 + 1});
                if(temp -> right) q.push({temp -> right, curr*2 + 2});
            }
            ans = max(ans, (int)(right - left + 1));
        }
        return ans;
    }
};