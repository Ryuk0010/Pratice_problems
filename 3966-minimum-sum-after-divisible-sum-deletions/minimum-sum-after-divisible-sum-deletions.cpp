class Solution {
public:
    long long minArraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long total = 0;
        for (int num : nums) total += num;

        vector<long long> dp(n + 1, 0);
        unordered_map<int, long long> best;
        best[0] = 0;

        long long prefix = 0;
        for (int i = 1; i <= n; i++) {
            prefix += nums[i - 1];
            int rem = prefix % k;

            dp[i] = dp[i - 1];

            if (best.count(rem)) {
                long long candidate = best[rem] + prefix;
                dp[i] = max(dp[i], candidate);
            }

            long long val = dp[i] - prefix;
            if (best.count(rem))
                best[rem] = max(best[rem], val);
            else
                best[rem] = val;
        }

        return total - dp[n];
    }
};
