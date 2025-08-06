class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), j = 0, maxSize = 0;

        for (int i = 0; i < n; i++) {
            while ((long long)nums[i] > (long long)k * nums[j]) j++;
            maxSize = max(maxSize, i - j + 1);
        }
        return n - maxSize;
    }
};