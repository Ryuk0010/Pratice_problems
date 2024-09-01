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
        int cCnt = 0;
        int m = connections.size();
        vector<vector<int>> adj(n);
        for(int i = 0; i < m; i++){
            int a = connections[i][0];
            int b = connections[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
            cCnt++;
        }
        if(cCnt < n-1) return -1;
        // for(int i = 0; i < n; i++){
        //     cout << i << "->";
        //     for(auto it: adj[i]){
        //         cout << it <<" ";
        //     }
        //     cout << endl;
        // }
        // return 0;
        int cnt = 0;
        int a = 0;
        vector<int> vis(n, 0);
        for(int i = 0; i < n; i++){
            if(!vis[i]) cnt = dfs(i, vis, adj, a);
        } 
        int extraConnection = abs(cCnt - cnt);
        int connNodes = cnt+1;
        int remNodes = n - connNodes;
        if(remNodes <= extraConnection) return remNodes;
        return -1;
        
    }
};