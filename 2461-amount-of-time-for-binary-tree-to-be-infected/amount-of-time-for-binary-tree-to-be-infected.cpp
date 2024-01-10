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
    void createGraph(TreeNode* current, TreeNode* parent, unordered_map<int , vector<int>> &adj){

        if(current){
            
            if(parent) adj[current->val].push_back(parent->val);

            if(current->left) adj[current->val].push_back(current->left->val);

            if(current->right) adj[current->val].push_back(current->right->val);

            createGraph(current->left, current, adj);
            createGraph(current->right, current, adj);
        }

        return;
    }
    int amountOfTime(TreeNode* root, int start) {
        
        unordered_map<int , vector<int>> adj;
        
        //create a graph for reverse traversal
        createGraph(root, NULL, adj);

        //BFS
        queue<int> q;
        unordered_set<int> visited;

        q.push(start);
        visited.insert(start);

        int minutes = 0;

        while(!q.empty()){
            
            int n = q.size();

            while(n--){

                int front = q.front();
                q.pop();

                for(int &neighbour : adj[front]){

                    if(visited.find(neighbour) == visited.end()){ //not infected

                        q.push(neighbour);
                        visited.insert(neighbour);
                    }
                }
            }
            minutes++;
        }

        return --minutes;
    }
};