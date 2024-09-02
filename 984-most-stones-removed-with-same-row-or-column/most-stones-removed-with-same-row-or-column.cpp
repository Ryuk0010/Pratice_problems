class Solution {
public:

    void dfs(vector<vector<int>>& adj, vector<bool>& vis, int i){
        vis[i] = 1;

        for(auto it: adj[i]){
            if((!vis[it])) dfs(adj, vis, it);
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<bool> vis(n);
        int connect = 0;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(adj, vis, i);
                connect++;
            }
        }
        return n - connect;
    }
};