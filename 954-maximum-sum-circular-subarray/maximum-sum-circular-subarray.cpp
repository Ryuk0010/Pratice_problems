class Solution {
public:
    int kadaneMax(vector<int>& nums, int n){
        int sum = nums[0];
        int maxi = nums[0];
        for(int i = 1; i < n; i++){
            sum = max(sum+nums[i], nums[i]);
            maxi = max(sum, maxi);
        }
        return maxi;
    }
    int kadaneMin(vector<int>& nums, int n){
        int sum = nums[0];
        int mini = nums[0];
        for(int i = 1; i < n; i++){
            sum = min(sum+nums[i], nums[i]);
            mini = min(sum, mini);
        }
        return mini;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int minSum = kadaneMin(nums, nums.size());
        int maxSum = kadaneMax(nums, nums.size());
        int ans = max(maxSum, sum-minSum);

        return(maxSum < 0)? maxSum : ans;
    }
};