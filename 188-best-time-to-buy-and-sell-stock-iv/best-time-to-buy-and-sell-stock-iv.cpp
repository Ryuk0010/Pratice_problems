class Solution {
public:
    int prof(int ind, int buy, int k, vector<int>& prices, vector<vector<vector<int>>>& dp){
        int n = prices.size();   
        if(k == 0) return 0;
        if(ind == n) return 0;
        if(dp[ind][buy][k] != -1)return dp[ind][buy][k];
        int profit = 0;
        if(buy) profit = max(prof(ind+1, 0, k, prices, dp) - prices[ind], prof(ind+1, 1, k, prices, dp));
        else profit = max(prof(ind+1, 1, k-1, prices, dp) + prices[ind], prof(ind+1, 0, k, prices, dp));
        return dp[ind][buy][k] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int buy = 1;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
        return prof(0, buy, k, prices, dp);
    }
};