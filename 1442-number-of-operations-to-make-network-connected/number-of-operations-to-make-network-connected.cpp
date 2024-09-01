class Solution {
public:
    int dfs(int i, vector<int>& vis, vector<vector<int>>& adj, int& cnt){
        vis[i] = 1;
        for(auto it: adj[i]){
            if(!vis[it]){
                dfs(it, vis, adj, cnt);
                cnt++;
            }
        }
        return cnt;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int cntAllConn = 0;
        int m = connections.size();
        vector<vector<int>> adj(n);
        for(int i = 0; i < m; i++){
            int a = connections[i][0];
            int b = connections[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
            cntAllConn++;
        }
        if(cntAllConn < n-1) return -1;
        int cntConn = 0;
        int a = 0;
        vector<int> vis(n, 0);
        for(int i = 0; i < n; i++){
            if(!vis[i]) cntConn = dfs(i, vis, adj, a);
        } 
        int extraConnection = abs(cntAllConn - cntConn);
        int remNodes = n - (cntConn + 1);
        if(remNodes <= extraConnection) return remNodes;
        return -1;
        
    }
};