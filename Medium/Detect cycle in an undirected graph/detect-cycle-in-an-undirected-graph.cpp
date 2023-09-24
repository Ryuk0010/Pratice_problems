//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool solve(int num, vector<int> adj[], int visited[]){
        queue<pair<int,int>> q;
        q.push({num, -1});
        visited[num] = 1;
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto ind: adj[node]){
                if(!visited[ind]){
                    visited[ind] = 1;
                    q.push({ind, node});
                }
                else if(parent != ind){
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        int visited[V] = {0};
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                if(solve(i, adj, visited)) return true;
            }
        }
        return false;
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends