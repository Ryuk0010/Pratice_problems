class Solution {
public:
    int dp[101];
    int solve(string s, int i, int n){
        if(i == n) return 1;
        if(s[i] == '0') return 0;
        if(dp[i] != -1) return dp[i];
        int ans = 0;
        ans += solve(s, i+1, n);
        if(i+1 < n){
            int num = (s[i] - '0') * 10 + (s[i+1] - '0');
            if(num <= 26) ans += solve(s, i+2, n);
        }
        return dp[i] = ans;
    }
    int numDecodings(string s) {
        memset(dp, -1, sizeof(dp));
        int n = s.length();
        return solve(s, 0, n);
    }
};