class Solution {
public:
    int solve(string word1, string word2, int i, int j, vector<vector<int>>& dp){
        if(i < 0) return j+1;
        if(j < 0) return i+1;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = INT_MAX;
        if(word1[i] == word2[j]) ans = solve(word1, word2, i-1, j-1, dp);
        int insert = 1 + solve(word1, word2, i, j - 1, dp);
        int del = 1 + solve(word1, word2, i - 1, j, dp);
        int replace = 1 + solve(word1, word2, i - 1, j - 1, dp);
        ans = min(ans, min(insert, min(del, replace)));
        return dp[i][j] = ans;
    }
    int minDistance(string word1, string word2) {
        int i = word1.length();
        int j = word2.length();
        vector<vector<int>> dp(i, vector<int>(j, -1));
        return solve(word1, word2, i-1, j-1, dp);
    }
};