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
class BSTIterator {
public:
    queue<TreeNode*> q;
    void solve(TreeNode* root){
      
      if(root->left) solve(root->left);
      q.push(root);
      if(root->right) solve(root->right);
    }
    BSTIterator(TreeNode* root) {
        solve(root);
    }
    
    int next() {
        TreeNode* ele = q.front();
        q.pop();
        return ele->val;
    }
    
    bool hasNext() {
        if(q.size() > 0) return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */