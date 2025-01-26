class Solution {
public:
map<vector<int>, int> mp;
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& need) {
        if(mp.count(need) != 0)return mp[need];
        int ans = 0;

        int n = price.size();
        for(int i = 0; i < n; i++){
            ans += price[i]*need[i];
        }
        for(int i = 0; i < special.size(); i++){
            bool isValid = 1;
            for(int j = 0; j < n; j++){
                if(need[j] < special[i][j]){ 
                    isValid = 0;
                    break;
                }
            }
            if(isValid){
                for(int j = 0; j < n; j++){
                    need[j] -= special[i][j];
                }
                int ans2 = special[i].back() + shoppingOffers(price, special, need);
                ans = min(ans, ans2);
                
                for(int j = 0; j < n; j++){
                    need[j] += special[i][j];
                }
            }
        }
        return mp[need] = ans;
    }
};