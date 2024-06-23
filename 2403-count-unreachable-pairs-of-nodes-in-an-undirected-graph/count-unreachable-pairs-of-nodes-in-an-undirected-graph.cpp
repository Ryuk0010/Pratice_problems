class Solution {
public:

    int dfs(int node, vector<bool> &visited, vector<vector<int>> &adj){
        visited[node] = true;
        int size = 1;
        for(auto it: adj[node]){
            if(!visited[it]){
                size += dfs(it, visited, adj);
            }
        }
        return size;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<bool> visited(n);
        vector<int> combinations(n);
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                combinations[i] = dfs(i, visited, adj);
            }
        }
        long long ans = 0;
        long long sum = 0;
        for(auto it: combinations){
            ans += sum * it;
            sum += it; 
        }
        return ans;
    }
};