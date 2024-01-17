class Solution {
private:
    int targetSum(vector<int> &nums, int target, int sum, int ind){
        if(ind == nums.size() && sum == target) return 1;
        if(ind >= nums.size()) return 0;
        // if(dp[ind][sum] != -1) return dp[ind][sum]; 
        int substract = targetSum(nums, target, sum - nums[ind], ind + 1);
        int add = targetSum(nums, target, sum + nums[ind], ind + 1);
        return (add + substract);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        // vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        
        return targetSum(nums, target, 0, 0);
    }
};