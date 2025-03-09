class Solution {
public:
    int solve(string word1, string word2, int i, int j, int dp[500][500]){
        if(i < 0) return j+1;
        if(j < 0) return i+1;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = INT_MAX;
        if(word1[i] == word2[j]) return solve(word1, word2, i-1, j-1, dp);
        int insert = 1 + solve(word1, word2, i, j - 1, dp);
        int del = 1 + solve(word1, word2, i - 1, j, dp);
        int replace = 1 + solve(word1, word2, i - 1, j - 1, dp);
        return dp[i][j] =  min(insert, min(del, replace));
    }
    int minDistance(string word1, string word2) {
        int i = word1.length();
        int j = word2.length();
        int dp[500][500];
        memset(dp, -1, sizeof(dp));
        return solve(word1, word2, i-1, j-1, dp);
    }
};