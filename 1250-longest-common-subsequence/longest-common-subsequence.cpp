class Solution {
private:
    int lcs(int ind1, int ind2, string s1, string s2, vector<vector<int>> &dp){
      if(ind1 < 0 || ind2 < 0) return 0;

      if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

      if(s1[ind1] == s2[ind2]) return dp[ind1][ind2] = (1 + lcs(ind1 - 1, ind2 - 1, s1, s2, dp));
      return dp[ind1][ind2] =  max(lcs(ind1 - 1, ind2, s1, s2, dp), lcs(ind1, ind2 - 1, s1, s2, dp));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
      int n = text1.size();
      int m = text2.size();
      vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        // return lcs(n - 1, m - 1, text1, text2, dp);
      for(int j=0;j<=m;j++){
				dp[0][j]=0;
			}
			for(int i=0;i<=n;i++){
				dp[i][0]=0;
			}

			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					if(text1[i - 1] == text2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
						else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
			}
			return dp[n][m];
    }
};