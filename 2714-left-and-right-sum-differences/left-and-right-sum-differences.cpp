class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        int sum = 0;
        ans[nums.size() - 1] = 0;
        for(int i = nums.size() - 1; i > 0; i--){
            sum += nums[i];
            ans[i-1] = sum;
        }
        sum = 0;
        for(int i = 1; i < nums.size(); i++){
            sum += nums[i-1];
            ans[i] = abs(ans[i] - sum);
        }
    return ans;
    }
};