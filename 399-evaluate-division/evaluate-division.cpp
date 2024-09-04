class Solution {
public:
    double dfs(string src, string dest, unordered_map<string, vector<pair<string, double>>> &adj, 
               unordered_set<string> &vis) {
        if (src == dest) return 1.0;  
        vis.insert(src);
        
        for (auto &neighbor : adj[src]) {
            string next = neighbor.first;
            double weight = neighbor.second;
            if (vis.find(next) == vis.end()) {  
                double result = dfs(next, dest, adj, vis);
                if (result != -1.0) {  
                    return result * weight;
                }
            }
        }
        return -1.0;  
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> adj;  // Adjacency list

        
        for (int i = 0; i < equations.size(); i++) {
            string a = equations[i][0];
            string b = equations[i][1];
            double wt = values[i];
            adj[a].push_back({b, wt});
            adj[b].push_back({a, 1.0 / wt});
        }

        vector<double> finalans;

        
        for (auto &query : queries) {
            string src = query[0];
            string dest = query[1];

            if (adj.find(src) == adj.end() || adj.find(dest) == adj.end()) {
                finalans.push_back(-1.0);  
            } else {
                unordered_set<string> vis;  
                double result = dfs(src, dest, adj, vis);
                finalans.push_back(result);
            }
        }
        return finalans;
    }
};
