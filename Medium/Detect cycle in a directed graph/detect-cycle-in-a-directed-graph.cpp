//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int degree[V] = {0};
        queue<int> q;
        vector<int> ans;
        for(int i=0; i<V; i++){
            for(auto it: adj[i]){
                degree[it]++;
            }
        }
        for(int i=0; i<V; i++){
            if(degree[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            
            ans.push_back(temp);
            for(auto it: adj[temp]){
                degree[it]--;
                if(degree[it] == 0) q.push(it);
            }
        }
        if(ans.size() == V) return 0;
        else return 1;
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
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends