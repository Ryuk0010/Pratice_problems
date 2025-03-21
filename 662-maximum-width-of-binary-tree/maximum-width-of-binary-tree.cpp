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
        q.push({root, 0});
        long long ans = 0;
        while(!q.empty()){
            int s = q.size();
            long long l = 0;
            long long r = 0;
            for(int i = 0; i < s; i++){
                auto node = q.front().first;
                long long curr = q.front().second;
                q.pop();
                if(i == 0) l = curr;
                if(i == s-1) r = curr;
                if(node->left) q.push({node->left, curr*2 + 1});
                if(node->right) q.push({node->right, curr*2 + 2});

            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};