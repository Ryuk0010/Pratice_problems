class Solution {
public:
    int uniquePathsHelper(int n, int m, vector<vector<int>>& dp, vector<vector<int>>& og){
        if(m < 0 || n < 0 || og[n][m] == 1) return 0;
        if(m == 0 && n == 0) return 1;
        if(dp[n][m] != -1) return dp[n][m];

        int top = uniquePathsHelper(n-1, m, dp, og);
        int left = uniquePathsHelper(n, m-1, dp, og);
        return dp[n][m] = top + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1) return 0;
        vector<vector<int>> dp(n, vector<int> (m, 0));
        // return uniquePathsHelper(n-1, m-1, dp, obstacleGrid);
        dp[0][0] = 1;
        for (int i = 1; i < n; i++) if(obstacleGrid[i][0] != 1) dp[i][0] = dp[i-1][0];
        for (int i = 1; i < m; i++) if(obstacleGrid[0][i] != 1) dp[0][i] = dp[0][i-1];
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if(obstacleGrid[i][j]) dp[i][j]=0;
                else dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[n-1][m-1];
        
    }
};