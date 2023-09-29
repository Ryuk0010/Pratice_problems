//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    bool safeState(int node, vector<int> adj[], int path[], int visit[], 
    int mark[]){
        visit[node] = 1;
        path[node] = 1;
        
        for(auto it: adj[node]){
            if(!visit[it]){
                if(safeState(it, adj, path, visit, mark)){
                    mark[node] = 0;
                    return true;
                }
            }
            else if(path[it]){
                mark[node] = 0;
                return true;
            }
        }
        mark[node] = 1;
        path[node] = 0;
        return false;
    }
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        int path[V] = {0};
        int visit[V] = {0};
        int mark[V] = {0};
        vector<int> safeNode;
        for(int i = 0; i < V; i++){
            if(!visit[i]){
                safeState(i, adj, path, visit, mark);
            }
        }
        for(int i = 0; i < V; i++){
            if(mark[i] == 1) safeNode.push_back(i);
        }
        return safeNode;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends