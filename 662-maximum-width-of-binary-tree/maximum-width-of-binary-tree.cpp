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
    long long widthOfBinaryTree(TreeNode* root) 
    {
        queue<pair<TreeNode* , int>>q;
        q.push({root , 0 });
        long long result = 0;
        while(!q.empty())
        {
           int size = q.size();

           long long left , right;
           
           for(int i = 0; i < size; i++)
           {
               long long curr_value = q.front().second;
               TreeNode* temp = q.front().first;
               q.pop();

               if(i == 0) 
               left = curr_value;
               if(i == size-1)
               right = curr_value;

               if(temp->left)
               q.push({temp->left , curr_value*2 + 1});
               if(temp->right)
               q.push({temp->right , curr_value*2 + 2});
           }

           result = max(result , right - left + 1);
        }
       return result;

    }
};