class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0) sum = 0;
            else sum++;
            ans = max(ans, sum);
        }
        return ans;
    }
};