class Solution {
public:
    int solve(int idx, vector<int>& price, vector<vector<int>>& special, vector<int>& needs){
        if(idx == special.size()){
            int ans = 0;
            for(int i = 0; i < needs.size(); i++){
                ans += price[i]*needs[i];
            }
            return ans;
        }
        int flag = 1;
        for(int i=0; i<price.size(); i++){
            if(special[idx][i] > needs[i]) flag = 0;
        }
        if(flag){
            for(int i=0; i<price.size(); i++){
                needs[i] -= special[idx][i];
            }
            int money = special[idx][price.size()] + solve(idx, price, special, needs);
            for(int i=0; i<price.size(); i++){
                needs[i] += special[idx][i];
            }
            return min(money, solve(idx+1, price, special, needs));
        }
        return solve(idx+1, price, special, needs);
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return solve(0, price, special, needs);
    }
};