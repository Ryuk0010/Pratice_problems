class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int sum = 0;
        int ans = INT_MIN;
        int n = nums.size();
        unordered_map<int, int> mpp;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            mpp[nums[i]]++;
        }
        for(int i = 0; i < n; i++){
            int two_x = sum - nums[i];

            if(two_x % 2) continue;

            mpp[nums[i]]--;
            int x = two_x / 2;
            if(mpp[x] > 0) ans = max(ans, nums[i]);
            mpp[nums[i]]++;
        }
        return ans;
    }
};