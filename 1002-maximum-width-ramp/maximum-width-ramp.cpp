class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<int>maxLeft(n, 0);
        maxLeft[n-1] = nums[n-1];
        for(int i = n - 2; i >= 0; i--){
            maxLeft[i] = max(nums[i], maxLeft[i+1]);
        }
        int l = 0, r = 0;
        int ans = 0;
        while(r < n){
            while(l > r || nums[l] > maxLeft[r]) l++;
            ans = max(ans, r - l);
            r++;
        } 
        return ans;
    }
};