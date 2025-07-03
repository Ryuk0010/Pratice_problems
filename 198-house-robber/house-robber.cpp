class Solution {
public:
    int solve(int ind, vector<int>& nums,  vector<int>& dp){
        if(ind == nums.size()-1) return nums[nums.size()-1];
        if(ind >= nums.size()) return 0;

        if(dp[ind] != -1) return dp[ind];

        int pick = nums[ind] + solve(ind+2, nums, dp);
        int notpick = solve(ind+1, nums, dp);
        return dp[ind] = max(pick, notpick);
    } 
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(0, nums, dp);
    }
};