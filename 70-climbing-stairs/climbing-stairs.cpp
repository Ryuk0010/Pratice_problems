class Solution {
private:
    int solve(int n, vector<int> &dp){
        if(n == 0) return 1;
        if(n == 1) return 1;
        if(dp[n] != -1) return dp[n];
        int count1 = solve(n - 1, dp);
        int count2 = solve(n - 2, dp);
        return dp[n] = count1 + count2;
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
};