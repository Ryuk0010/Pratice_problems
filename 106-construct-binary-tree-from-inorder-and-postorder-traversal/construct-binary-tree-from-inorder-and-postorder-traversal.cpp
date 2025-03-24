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
    unordered_map<int, int> mpp;
    TreeNode* solve(vector<int>& postorder, int s, int e, int &idx){
        if(s > e) return nullptr;
        int node = postorder[idx--];
        TreeNode* root = new TreeNode(node);
        int mid = mpp[node];

        root->right = solve(postorder, mid+1, e, idx);
        root->left = solve(postorder, s, mid-1, idx);
        
        
        return root;
        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int n = inorder.size();
        for(int i = 0; i < n; i++) mpp[inorder[i]] = i;
        int idx = n-1;
        return solve(postorder, 0, n-1, idx);
    }
};