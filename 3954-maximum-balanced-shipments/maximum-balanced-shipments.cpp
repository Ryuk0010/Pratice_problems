class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int maxi = INT_MIN;
        int cnt = 0;
        for(int i = 0; i < weight.size(); i++){
            if(maxi > weight[i]){
                cnt++;
                maxi = 0;
            }
            else maxi = max(maxi, weight[i]);
        }
        return cnt;
    }
};