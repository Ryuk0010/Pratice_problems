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
        int n = word1.length();
        int m = word2.length();
        int dp[502][502];
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i <= n; i++) dp[i][0] = i;
        for(int i = 0; i <= m; i++) dp[0][i] = i;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
                else{
                    int insert = 1 + dp[i][j - 1];
                    int del = 1 + dp[i - 1][j];
                    int replace = 1 + dp[i - 1][j - 1];
                    dp[i][j] = min(insert, min(del, replace));
                }

            }
        }
        return dp[n][m];
    }
};