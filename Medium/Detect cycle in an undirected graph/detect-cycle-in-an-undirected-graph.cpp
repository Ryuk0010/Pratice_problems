//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
   bool dfs(vector<int> &visit,vector<int> a[],int i,int parent){
        visit[i] = 1;
        for(auto x: a[i]){
            if(!visit[x]){
                if(dfs(visit,a,x,i)) return 1;
            }
            else if(parent != x) return 1;
        }
        return 0;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> visit(V,0);
        for(int i=0;i<V;i++){
            if(!visit[i]){
                if(dfs(visit,adj,i,-1)) return 1;
            }
        }
        return 0;
        
        
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