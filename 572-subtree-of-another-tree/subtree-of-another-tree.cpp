class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot == NULL){
            return true;
        }
        if (root == NULL) {
            return false;
        }
        if (same(root, subRoot)) {
            return true;
        }
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
private:
    bool same(TreeNode* r, TreeNode* s) {
        if (r == NULL && s == NULL) {
            return true;
        }
        if (r == NULL || s == NULL) {
            return false;
        }
        if (r->val != s->val) {
            return false;
        }
        return same(r->left, s->left) && same(r->right, s->right);
    }
};