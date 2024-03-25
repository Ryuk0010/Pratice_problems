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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
      stack<TreeNode*> st;
      int j = 0;
      TreeNode* head = nullptr;
      for(int i = 0; i < preorder.size(); i++){
        TreeNode* root = new TreeNode(preorder[i]);
        if(i == 0) head = root;
        if (!st.empty()){
          if(!(st.top()->left)) st.top()->left = root;
          else st.top()->right = root;
        }
        st.push(root);
        while(!st.empty() && postorder[j] == st.top()->val){
          st.pop();
          j++;
        }
      }
      return head;
    }
};