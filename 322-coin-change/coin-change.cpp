class Solution {
public:
    int solve(vector<int>& coins, int amt, int n, vector<vector<int>>& dp){
        if(n < 0) return INT_MAX-1;
        if(amt == 0) return 0;
        if(dp[n][amt] != -1) return dp[n][amt];
        int take = INT_MAX-1;
        if(amt >= coins[n]) take = solve(coins, amt-coins[n], n, dp) + 1;
        int nottake = solve(coins, amt, n-1, dp);
        return dp[n][amt] = min(take, nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int ans = solve(coins, amount, n-1, dp);
        return (ans >= INT_MAX - 1) ? -1 : ans;
    }
};