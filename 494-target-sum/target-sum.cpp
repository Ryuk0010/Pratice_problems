class Solution {
private:
    int numOfSubsets(int i, int target, vector<int>& nums, vector<vector<int>>& dp){
        if(i == 0) {
            if(target == 0 and nums[0] == 0) {
                return 2;
            }
            if(target == nums[0] or target == 0) {
                return 1;
            }
            return 0;
        }
        if(dp[i][target] != -1) return dp[i][target];
        
        int notTake = numOfSubsets(i-1, target, nums, dp);
        int take = 0;
        if(target >= nums[i]) {
            take = numOfSubsets(i-1, target - nums[i], nums, dp);
        }

        return dp[i][target] = take + notTake;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalSum = 0;
        for(int i = 0; i < n; i++) {
            totalSum += nums[i];
        }
        int newTarget = (totalSum + target);
        if(newTarget%2 != 0 or newTarget < 0) {
            return 0;
        }
        newTarget /= 2;
        if(target > totalSum) return 0;
        vector<vector<int>> dp(n, vector<int>(newTarget+1, -1));

        return numOfSubsets(n-1, newTarget, nums, dp);
    }
};