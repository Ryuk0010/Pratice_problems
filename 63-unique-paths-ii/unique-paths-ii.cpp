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

        vector<vector<int>> dp(n, vector<int> (m, -1));
        return uniquePathsHelper(n-1, m-1, dp, obstacleGrid);
        
    }
};