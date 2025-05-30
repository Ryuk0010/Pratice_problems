class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int b = prices[0];
        for(int i = 0; i < prices.size(); i++){
            ans = max(ans, prices[i] - b);
            if(b > prices[i]) b = prices[i];
        }
        return ans;
    }
};