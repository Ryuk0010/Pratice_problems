class Solution {
public:
  

int countPaths(int n, vector<vector<int>>& roads) {
    int m = roads.size();
    vector<vector<pair<long long, long long>>> adj(n);

    for (int i = 0; i < m; i++) {
        long long u = roads[i][0];
        long long v = roads[i][1];
        long long wt = roads[i][2];
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    vector<long long> dist(n, LLONG_MAX);
    vector<long long> ways(n, 0);
    int mod = 1e9 + 7;

    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
    
   
    dist[0] = 0;
    ways[0] = 1;
    pq.push({0, 0});  

    while (!pq.empty()) {
        long long cost = pq.top().first;
        long long node = pq.top().second;
        pq.pop();

        // if (cost > dist[node]) continue;  

        for (auto x : adj[node]) {
            long long adjNode = x.first;
            long long wt = x.second;

            if (dist[adjNode] > cost + wt) {
                dist[adjNode] = cost + wt;
                ways[adjNode] = ways[node];  
                pq.push({dist[adjNode], adjNode});
            } 
            else if (dist[adjNode] == cost + wt) {
                ways[adjNode] = (ways[adjNode] + ways[node]) % mod; 
            }
        }
    }

    return ways[n - 1] % mod;
}

};