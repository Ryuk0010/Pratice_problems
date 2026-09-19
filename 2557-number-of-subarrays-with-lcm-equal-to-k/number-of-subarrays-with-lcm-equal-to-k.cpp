class Solution {
public:
using ll = long long;
    int subarrayLCM(vector<int>& nums, int k) {
        int l(0), cnt(0);
        for(int i = 0; i < nums.size(); i++){
            ll g = nums[i];
            if(nums[i] == k){
                cnt++;
            }
            for(int j = i+1; j < nums.size(); j++){
                g = lcm(g,(ll)nums[j]);
               if(g==k){
                cnt++;
               }
               if(g>k){
                break;
               }
            }
        }
        return cnt;
    }
};