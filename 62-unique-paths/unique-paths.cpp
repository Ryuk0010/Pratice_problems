class Solution {
public:
    int uniquePathsHelper(int n, int m, vector<vector<int>>& dp){
        if(m < 0 || n < 0) return 0;
        if(m == 0 && n == 0) return 1;
        if(dp[n][m] != -1) return dp[n][m];

        int top = uniquePathsHelper(n-1, m, dp);
        int left = uniquePathsHelper(n, m-1, dp);
        return dp[n][m] = top + left;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return uniquePathsHelper(n-1, m-1, dp);
    }
};