class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int buy = prices[0];
        for(int i = 0; i < prices.size(); i++){
            ans = max(ans, prices[i] - buy);
            if(buy > prices[i]) buy = prices[i];
        }
        return ans;
    }
};