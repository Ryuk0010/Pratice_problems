class Solution {
public:
    int dp[12][10001];
    int solve(vector<int>& coins, int amt, int n){
        if(n < 0) return INT_MAX-1;
        if(amt == 0) return 0;
        if(dp[n][amt] != -1) return dp[n][amt];
        int take = INT_MAX-1;
        if(amt >= coins[n]) take = solve(coins, amt-coins[n], n) + 1;
        int nottake = solve(coins, amt, n-1);
        return dp[n][amt] = min(take, nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        // int n = coins.size();
        // memset(dp, -1, sizeof(dp));
        // int ans = solve(coins, amount, n-1);
        // return (ans >= INT_MAX - 1) ? -1 : ans;
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, INT_MAX - 1));
        for(int i = 0; i <= n; i++) dp[i][0] = 0;
        for(int i = 1; i <= n; i++) {
            for(int amt = 1; amt <= amount; amt++) {
                int take = INT_MAX - 1;
                if(amt >= coins[i - 1])
                    take = dp[i][amt - coins[i - 1]] + 1;
                int nottake = dp[i - 1][amt];
                dp[i][amt] = min(take, nottake);
            }
        }
        return dp[n][amount] >= INT_MAX - 1 ? -1 : dp[n][amount];
    }
};