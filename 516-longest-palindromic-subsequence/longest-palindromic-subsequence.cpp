class Solution {
public:
int dp[1001][1001] = {0};
    int solve(int i, int j, string &s){
        if(i > j) return 0;
        if(i == j) return 1;
        if(dp[i][j] != 0) return dp[i][j];

        if(s[i] == s[j]) return dp[i][j] =  2 + solve(i+1, j-1, s);
        return dp[i][j] =  max(solve(i+1, j, s), solve(i, j-1, s));

    }
    int longestPalindromeSubseq(string s) {
        
        return solve(0, s.length()-1, s);
    }
};