/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void findPar(unordered_map<TreeNode*, TreeNode*>& parent, TreeNode* root){
        parent[root] = nullptr;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int s = q.size();
            for(int i = 0; i < s; i++){
                auto node = q.front();
                q.pop();
                if(node->left) {
                    q.push(node->left);
                    parent[node->left] = node;
                }
                if(node->right) {
                    q.push(node->right);
                    parent[node->right] = node;
                }
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        unordered_map<int, int> vis;
        findPar(parent, root);
        queue<TreeNode*> q;
        q.push(target);
        vis[target->val] = 1;
        while(k-- && !q.empty()){
            int s = q.size();
            for(int i = 0; i < s; i++){
                auto node = q.front();
                q.pop();
                if(node->left && vis[node->left->val]==0){ 
                    q.push(node->left);
                    vis[node->left->val] = 1;
                }
                if(node->right && vis[node->right->val]==0){ 
                    q.push(node->right);
                    vis[node->right->val] = 1;
                }
                if(parent[node] && vis[parent[node]->val]==0){ 
                    q.push(parent[node]);
                    vis[parent[node]->val] = 1;
                }
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int a = q.front()->val;
            ans.push_back(a);
            q.pop();
        }
        return ans;
    }
};