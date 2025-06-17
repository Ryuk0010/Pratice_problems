class Solution {
public:
    int solve(vector<vector<int>>& grid, int n, int m, vector<vector<int>>& dp){
        if(n < 0 || m < 0 || grid[n][m] == 1) return 0;
        if(n == 0 && m == 0) return 1;
        if(dp[n][m] != -1) return dp[n][m];
        return dp[n][m] = solve(grid, n-1, m, dp) + solve(grid, n, m-1, dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(obstacleGrid, n-1, m-1, dp);
    }
};