class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            if(sum < 0) sum = 0;
            sum += nums[i];
            ans = max(sum, ans);
        }
        return ans;
    }
};