class Solution {
public:
    int solve(int i, int j, vector<int>& nums, vector<vector<int>>& dp){
        if(i >= nums.size()) return 0;
        if(dp[i][j+1] != -1) return dp[i][j+1];
        int ans1 = 0, ans2 = 0;
        if(j == -1 || nums[i] > nums[j]) ans1 = 1 + solve(i+1, i, nums, dp);
        ans2 = solve(i+1, j, nums, dp);
        return dp[i][j+1] = max(ans1, ans2);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));

        return solve(0, -1, nums, dp);
    }
};