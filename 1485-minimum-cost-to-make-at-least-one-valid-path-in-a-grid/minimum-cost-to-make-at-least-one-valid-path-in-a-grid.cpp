class Solution {
public:
    bool valid(int x, int y, int n, int m, vector<vector<bool>> &visited) {
        return x >= 0 && y >= 0 && x < n && y < m && !visited[x][y];
    }
    
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<vector<int>> dp(n, vector<int>(m, 1e5));
        
        deque<pair<pair<int, int>, int>> q;
        q.push_back({{0, 0}, 0});
        
        while (!q.empty()) {
            auto [pos, cost] = q.front();
            q.pop_front();
            auto [x, y] = pos;
            
            if (visited[x][y]) continue;
            
            visited[x][y] = true;
            dp[x][y] = min(dp[x][y], cost);
            
            for (int i = 0; i < 4; ++i) {
                int newX = x + dir[i].first, newY = y + dir[i].second;
                if (valid(newX, newY, n, m, visited)) {
                    if (grid[x][y] == i + 1)
                        q.push_front({{newX, newY}, cost});
                    else 
                        q.push_back({{newX, newY}, cost + 1});
                }
            }
        }
        return dp[n-1][m-1];
    }
};