class Solution {
public:
    void floydWarshall(vector<vector<int>>& dist, int n) {
        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                    if (i == j) dist[i][j] = 0;
                }
            }
        }
    }

    vector<int> dijkstra(int node, vector<vector<pair<int, int>>>& adj, int n) {
        vector<int> dist(n, INT_MAX);
        dist[node] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, node});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (auto it : adj[u]) {
                int v = it.first;
                int wt = it.second;
                if (dist[v] > dist[u] + wt) {
                    dist[v] = dist[u] + wt;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto it : edges) {
            int src = it[0];
            int dest = it[1];
            int wt = it[2];
            adj[src].push_back({dest, wt});
            adj[dest].push_back({src, wt});
        }

        vector<vector<int>> dist(n, vector<int>(n, 1e4 + 1));

        for (auto it : edges) {
            int src = it[0];
            int dest = it[1];
            int wt = it[2];
            dist[src][dest] = wt;
            dist[dest][src] = wt;
        }

        // floydWarshall(dist, n);
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < n; j++) {
        //         cout << dist[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        int ans = -1;
        int miniCity = INT_MAX;

        for (int i = 0; i < n; i++) {
            vector<int> dist = dijkstra(i, adj, n);
            int cnt = 0;

            for (int j = 0; j < n; j++) {
                if (dist[j] <= distanceThreshold) {
                    cnt++;
                }
            }

            if (cnt <= miniCity) {
                miniCity = cnt;
                ans = i;
            }
        }

        return ans;
    }
};
