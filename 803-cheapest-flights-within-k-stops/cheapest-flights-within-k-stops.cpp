class Solution {
    int dp[101][101];
    const int inf = 1e8;
private: 

    int dfs(int k, int node, int dst, vector<int> adj[], vector<vector<int>>& cost){
        if(k < 0) return inf;
        if(node == dst) return 0;

        if(dp[node][k] != -1) return dp[node][k];

        int ans = inf;
        for(auto it: adj[node]){
            ans = min(ans, cost[node][it] + dfs(k-1, it, dst, adj, cost));
        } 
        return dp[node][k] = ans;


    }
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        memset(dp, -1, sizeof dp);
        vector<int> adj[n];
        vector<vector<int>> cost(n, vector<int>(n));
        for(int i = 0; i < flights.size(); i++){
            int src = flights[i][0];
            int dest = flights[i][1];
            int cst = flights[i][2];
            adj[src].push_back(dest);
            cost[src][dest] = cst;
        }
        int ans = dfs(k + 1, src, dst, adj, cost);
        return ans == inf ? -1 : ans;
    }
};