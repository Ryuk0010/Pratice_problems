
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int, int>>> graph(n + 1);
        for (auto& t : times) {
            int src = t[0], des = t[1], time = t[2];
            graph[src].push_back({des, time});
        }

       
        queue<pair<int, int>> pq;
        vector<int> dist(n + 1, INT_MAX);
        
        dist[k] = 0;
        pq.push({0, k}); // {time, node}

        while (!pq.empty()) {
            auto [cost, node] = pq.front();
            pq.pop();
            
            for (auto& [neighbor, weight] : graph[node]) {
                if (cost + weight < dist[neighbor]) {
                    dist[neighbor] = cost + weight;
                    pq.push({dist[neighbor], neighbor});
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }

        return ans;
    }
};