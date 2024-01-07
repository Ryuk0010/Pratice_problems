class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int result = 0;

        // Dynamic programming table
        vector<unordered_map<long long, int>> dp(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                // Calculate the difference
                long long diff = (long long)nums[i] - nums[j];

                // Update dp table and count valid slices
                dp[i][diff] += dp[j][diff] + 1;
                result += dp[j][diff];
            }
        }

        return result;
    }
};