//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        int n=V;
        vector<int>indegree(n, 0);
        vector<vector<int>>rGraph(n, vector<int>());
        for(int i=0; i<n; i++){
            for(auto it:adj[i]){
                rGraph[it].push_back(i);
                indegree[i]++;
            }
        }

        vector<int>safeNodes;
        queue<int>q;
        for(int i=0; i<n; i++){
            if(indegree[i]==0) q.push(i);
        }

        while(!q.empty()){
            int node=q.front();
            q.pop();
            safeNodes.push_back(node);

            for(auto it:rGraph[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
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