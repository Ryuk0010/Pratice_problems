class Solution {
public:
    bool solve(vector<int>& nums, int idx, int n, vector<int>& dp){
        if(idx >= n-1) return true;
        if(dp[idx] != -1) return dp[idx];
        for(int i = 1; i <= nums[idx]; i++){
            if(solve(nums, idx+i, n, dp)) return dp[idx] = 1;
        }
        return dp[idx] = 0;
    }
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return solve(nums, 0, nums.size(), dp);
    }
};