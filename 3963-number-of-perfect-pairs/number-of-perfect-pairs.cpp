class Solution {
public:
    long long perfectPairs(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] < 0) nums[i] *= -1;
        }
        sort(nums.begin(), nums.end());
        long long cnt = 0;
        int j = 0;
        for(int i = 0; i < n; i++){
            while(j < n && (nums[i] + nums[j] >= max(nums[i], nums[j]) && abs(nums[i] - nums[j]) <= min(nums[i], nums[j]))) j++;
            cnt += j-i-1;
        }
        return cnt;
    }
};