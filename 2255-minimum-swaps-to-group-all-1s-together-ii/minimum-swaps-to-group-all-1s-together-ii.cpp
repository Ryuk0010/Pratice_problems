class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int k = accumulate(nums.begin(), nums.end(), 0);
        int cnt = accumulate(nums.begin(), nums.begin() + k, 0);
        int n = nums.size();
        int total = 0;
        for(int i = 0; i < n; i++){
            total = max(total, cnt);
            cnt -= nums[i];
            cnt += nums[(i+k) % n];
        }
        return k-total;
    }
};