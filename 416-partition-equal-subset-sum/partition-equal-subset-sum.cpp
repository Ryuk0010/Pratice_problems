class Solution {
public:
    bool solve(vector<int>& nums, int i, int sum, int s2, vector<vector<int>> &dp){
        if(i == nums.size()) return false;
        if(sum - s2 == s2) return true;
        if(dp[i][s2] != -1) return dp[i][s2];

        bool a = solve(nums, i+1, sum, s2 + nums[i], dp);
        bool b = solve(nums, i+1, sum, s2, dp);
        return dp[i][s2] = a | b;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i = 0; i < nums.size(); i++) sum += nums[i];
        vector<vector<int>> dp(n, vector<int>(sum, -1));

        return solve(nums, 0, sum, 0, dp);
    }
};