class Solution {
public:
    int solve(vector<int>& nums, int pos, vector<int>& dp){
        if(pos >= nums.size()-1) return 0;
        if(dp[pos] != 10001) return dp[pos];
        for(int i = 1; i <= nums[pos]; i++){
            dp[pos] = min(dp[pos], 1 + solve(nums, pos + i, dp));
        }
        return dp[pos];
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 10001);
        // return solve(nums, 0, dp);
        dp[n-1] = 0;
        for(int i = n-2; i >= 0; i--){
            for(int jump = 1; jump <= nums[i]; jump++){
                dp[i] = min(dp[i], 1+dp[min(n-1, i+jump)]);
            }
        }
        return dp[0];
    }
};