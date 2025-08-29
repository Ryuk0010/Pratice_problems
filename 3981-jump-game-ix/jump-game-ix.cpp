class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n, INT_MIN), suff(n, INT_MAX), ans(n, 0);
        for(int i = 0; i < n; i++){
            if(i) pref[i] = max(nums[i], pref[i-1]);
            else pref[i] = nums[i];
        }
        for(int i = n-1; i >= 0; i--){
            if(i < n-1) suff[i] = min(nums[i], suff[i+1]);
            else suff[i] = nums[i];
        }
        ans[n-1] = pref[n-1];
        for(int i = n-2; i >= 0; i--){
            ans[i] = pref[i];
            if(pref[i] > suff[i+1]) ans[i] = max(ans[i+1], ans[i]);
        }
        return ans;
    }
};