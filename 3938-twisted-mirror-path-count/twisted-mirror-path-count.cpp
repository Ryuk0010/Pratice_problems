class Solution {
public:
    int const mod = 1e9 + 7;
    int n, m;
    long long solve(int i, int j, int dir, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp){
        if(i == n - 1 && j == m - 1) return 1;
        if(i >= n || j >= m) return 0;
        if(dp[i][j][dir] != -1) return dp[i][j][dir];
        long long ans = 0;
            if(grid[i][j] == 1){
                if(dir) ans += solve(i+1, j, 0, grid, dp);
                else if(!dir) ans += solve(i, j+1, 1, grid, dp);
            }
            else{
                ans += solve(i, j+1, 1, grid, dp);
                ans += solve(i+1, j, 0, grid, dp);
            }
            
        return dp[i][j][dir] = ans % mod;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(2, -1)));
        return solve(0, 0, 0, grid, dp);
    }
};