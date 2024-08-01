class Solution {
public:
    // int help(vector<int>& coins, int amount, int n,vector<vector<int>>&h)
    // {
    //     if(amount == 0) return 0;
    //     if(n < 0 || amount < 0) return INT_MAX-1;
    //     if(h[n][amount]!= -1) return h[n][amount];
    //     int one = help(coins,amount,n-1,h);
    //     int two = 1+help(coins,amount-coins[n],n,h);
    //     h[n][amount] = min(one,two);
    //     return h[n][amount];
    // }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
        
        for(int t=0; t<=amount; t++) {
            dp[0][t] = t % coins[0] == 0 ? t / coins[0] : 1e9;
        }

        for(int i=1; i<n; i++) {
            for(int t=0; t<=amount; t++) {
                int notPick = 0 + dp[i - 1][t];
                int pick = coins[i] <= t ? 1 + dp[i][t - coins[i]] : 1e9;

                dp[i][t] = min(pick, notPick);
            }
        }
        return dp[n - 1][amount] == 1e9 ? -1 : dp[n - 1][amount];
    }
};