class Solution {
private:
    long solve(int amount, vector<int>& coins, int ind, vector<vector<int>>& dp){
      if(ind == 0){
        if(amount % coins[ind] == 0) return 1;
        return 0;
      }
      if(dp[ind][amount] != -1) return dp[ind][amount];
      int notTake = solve(amount, coins, ind - 1, dp);
      int take = 0;
      if(coins[ind] <= amount){
        take = solve(amount - coins[ind], coins, ind, dp);
      }
      return dp[ind][amount] = (notTake + take);
    }
public:
    int change(int amount, vector<int>& coins) {
      vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -1));
        return solve(amount, coins, coins.size()-1, dp);
    }
};