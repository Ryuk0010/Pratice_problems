class Solution {
public:
    int solve(string s, int n, int ind, vector<int> dp){
        if(ind == n) return 1;
        if(dp[ind] != -1) return dp[ind];
        if(s[ind] == '0') return 0;
        int ans = solve(s, n, ind+1, dp);
        if(ind+1 < n && (s[ind] == '1' ||(s[ind] == '2' && s[ind+1] <= '6'))){
            ans += solve(s, n, ind+2, dp);
        }
        return dp[ind] = ans;
    }
    int numDecodings(string s) {
        if(s[0] == '0') return 0;
        int n = s.length();
        vector<int> dp(n+1, 0);
        // return solve(s, n, 0, dp);
        dp[0]=1, dp[1] = 1;
        for(int i = 2; i <= n; i++){
            int a = s[i-1] - '0';
            int b = stoi(s.substr(i-2, 2));

            if(a != 0) dp[i] += dp[i-1];
            if(b >= 10 && b <= 26) dp[i] += dp[i-2];
        }
        return dp[n];
    }
};