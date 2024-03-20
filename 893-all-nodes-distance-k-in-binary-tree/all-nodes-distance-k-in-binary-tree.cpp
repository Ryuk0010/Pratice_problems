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
    void parent(TreeNode* root, TreeNode* target, int k, unordered_map<TreeNode*, TreeNode*>& mpp){
      queue<TreeNode*> q;
      q.push(root);
      mpp[root] = nullptr;
      while(!q.empty()){
        int size = q.size();
        TreeNode* temp = q.front();
        q.pop();
        // cout << temp->val;
        if(temp->left){
          q.push(temp->left);
          mpp[temp->left] = temp;
        } 
        if(temp->right){
          q.push(temp->right);
          mpp[temp->right] = temp;
        } 
      }
      return;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
       queue<TreeNode*> q;
        unordered_map<int,int> visited;
        unordered_map<TreeNode*,TreeNode*> mpp;
        vector<int> ans;

        parent(root,target,k,mpp);
        // for(auto it: mpp){
        //   cout << it.first->val <<" " << it.second->val << endl;
        // }

        q.push(target);// starting node will be our given target just like in graphs
        
        while(k-- && !q.empty()) { // will continue till it has reached a distance of k or level k 
            int size = q.size();

            while(size--) {
                TreeNode *Node = q.front();
                q.pop();
                visited[Node->val] = 1;

                if(Node->left && visited[Node->left->val] != 1 ) 
                    q.push(Node->left);
                   
                if(Node->right && visited[Node->right->val] != 1 ) 
                    q.push(Node->right);
                  
                if(mpp[Node]  && visited[mpp[Node]->val] != 1 ) 
                    q.push(mpp[Node]);
                
            }
        }
      while(!q.empty()){
          int temp = q.front()->val;
          // cout << temp;
          q.pop();
          ans.push_back(temp);
          
        }
        // cout << mpp[target];
      return ans;
    }
};