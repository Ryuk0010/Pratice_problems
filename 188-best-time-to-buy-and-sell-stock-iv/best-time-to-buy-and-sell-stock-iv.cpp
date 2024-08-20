class Solution {
public:
    int prof(int ind, int buy, int k, vector<int>& prices, vector<vector<vector<int>>>& dp){
        int n = prices.size();   
        if(k == 0) return 0;
        if(ind == n) return 0;
        if(dp[ind][k][buy] != -1)return dp[ind][k][buy];
        int profit = 0;
        if(buy) profit = max(prof(ind+1, 0, k, prices, dp) - prices[ind], prof(ind+1, 1, k, prices, dp));
        else profit = max(prof(ind+1, 1, k-1, prices, dp) + prices[ind], prof(ind+1, 0, k, prices, dp));
        return dp[ind][k][buy] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int buy = 1;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k+1, vector<int>(2, -1)));
        return prof(0, buy, k, prices, dp);
    }
};