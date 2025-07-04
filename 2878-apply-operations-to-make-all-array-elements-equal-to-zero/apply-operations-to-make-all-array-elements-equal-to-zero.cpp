class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n, 0);
        int carry = 0;
        for(int i = 0; i < n; i++){
            carry += ans[i];
            nums[i] += carry;

            if(nums[i] == 0) continue;
            if(nums[i] < 0) return false;
            if(i+k > n) return false;

            carry -= nums[i];
            if(i+k < n)ans[i+k] = nums[i];
        }
        return true;
    }
};