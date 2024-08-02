class Solution {
private:
    int solve(string s, int n, int ind, vector<int> &dp){
        if(ind == n) return 1;
        if(dp[ind] != -1) return dp[ind];
        if(s[ind] == '0') return 0;
        int ans = solve(s, n, ind+1, dp);
        if(ind+1 < n && (s[ind] == '1' || (s[ind] == '2' && s[ind+1] <= '6')))
        ans += solve(s, n, ind+2, dp);

        return dp[ind] = ans;
    }
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1, -1);
        return solve(s, n, 0, dp);
    }
};