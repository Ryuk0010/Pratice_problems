class Solution {
private:
    int solve(string word1, string word2, int n, int m, vector<vector<int>> &dp){
        if(n == 0) return (m);
        if(m == 0) return (n);
        if(dp[n][m] != -1) return dp[n][m];
        if(word1[n - 1] == word2[m - 1]) return solve(word1, word2, n - 1, m - 1, dp);

        int insert = 1 + solve(word1, word2, n, m - 1, dp);
        int del = 1 + solve(word1, word2, n - 1, m, dp);
        int replace = 1 + solve(word1, word2, n - 1, m - 1, dp);
        return dp[n][m] = min(insert, min(del, replace));
    }

 public:
  int minDistance(string word1, string word2) {
    const int m = word1.length();
    const int n = word2.length();
    
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    for (int i = 1; i <= m; ++i)
      dp[i][0] = i;

    for (int j = 1; j <= n; ++j)
      dp[0][j] = j;

    for (int i = 1; i <= m; ++i){
      for (int j = 1; j <= n; ++j){
        if (word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
        else dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
      }
    }
    return dp[m][n];
  }
};