class Solution {

    unordered_map<int, int> mapping;

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        mapping.clear();
        for (int i = 0; i < inorder.size(); i++) {
            mapping[inorder[i]] = i;
        }
        int preorderIndex;
        preorderIndex = 0;
        return build(preorder, preorderIndex, 0, inorder.size() - 1);
    }

    TreeNode* build(vector<int>& preorder, int& preorderIndex, int start, int end) {
        if (start > end) return nullptr;

        int rootVal = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(rootVal);
        int mid = mapping[rootVal];

        root->left = build(preorder, preorderIndex, start, mid - 1);
        root->right = build(preorder, preorderIndex, mid + 1, end);

        return root;
    }    
};