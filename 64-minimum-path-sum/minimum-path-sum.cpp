class Solution {
public:
    int solve(int n, int m, vector<vector<int>> &grid, vector<vector<int>> &dp){
        if(n < 0 || m < 0) return 100000;
        if(n == 0 && m == 0) return grid[n][m];
        if(dp[n][m] != -1) return dp[n][m];
        int up = grid[n][m] + solve(n-1, m, grid, dp);
        int left = grid[n][m] + solve(n, m-1, grid, dp);
        return dp[n][m] = min(up, left);
    } 
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        // return solve(n-1, m-1, grid, dp);
        for(int i = 0; i< n; i++){
            for(int j = 0; j< m; j++){
                if(i == 0  && j == 0) dp[i][j] = grid[i][j];
                else{
                    int up = 100000;
                    if(i > 0) up = grid[i][j] + dp[i-1][j];
                    int left = 100000;
                    if(j > 0) left = grid[i][j] + dp[i][j-1];
                    dp[i][j] = min(up, left);
                }
            }
        }
        return dp[n-1][m-1];
    }
};