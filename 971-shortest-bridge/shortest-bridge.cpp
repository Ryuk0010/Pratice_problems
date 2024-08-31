class Solution {
public:
    void dfs(int r, int c, int cnt, vector<vector<int>>& vis, vector<vector<int>>& grid) {
        int n = vis.size();
        vis[r][c] = cnt;
        int rw[] = {0, 0, -1, 1};
        int cl[] = {-1, 1, 0, 0};
        for (int i = 0; i < 4; i++) {
            int nr = r + rw[i];
            int nc = c + cl[i];
            if (nr < n && nr >= 0 && nc < n && nc >= 0 && vis[nr][nc] == 0 && grid[nr][nc] == 1) {
                dfs(nr, nc, cnt, vis, grid);
            }
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> vis(n, vector<int>(n, 0));
        int cnt = 1;
        
       
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    dfs(i, j, cnt, vis, grid);
                    cnt++;
                }
            }
        }

        queue<pair<int, pair<int, int>>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (vis[i][j] == 1) q.push({0, {i, j}});
            }
        }

        int ans = INT_MAX;
        while (!q.empty()) {
            auto p = q.front();
            q.pop();

            int dist = p.first;
            int r = p.second.first;
            int c = p.second.second;

            int rw[] = {0, 0, -1, 1};
            int cl[] = {-1, 1, 0, 0};
            for (int i = 0; i < 4; i++) {
                int nr = r + rw[i];
                int nc = c + cl[i];
                if (nr < n && nr >= 0 && nc < n && nc >= 0) {
                    if (vis[nr][nc] == 2) {
                        ans = min(ans, dist);
                    } else if (grid[nr][nc] == 0 && vis[nr][nc] == 0) {
                        vis[nr][nc] = 1;
                        q.push({dist + 1, {nr, nc}});
                    }
                }
            }
        }

        return ans;
    }
};
