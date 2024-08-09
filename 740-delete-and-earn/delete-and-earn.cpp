class Solution {
public:
   int solve(int n, vector<int>& nums, vector<int>& dp, vector<int>& freq) {
        if (n <= 0) return 0;
        if (dp[n] != -1) return dp[n];
        int notTake = solve(n-1, nums, dp, freq);
        int take = freq[n] + solve(n-2, nums, dp, freq);
        return dp[n] = max(notTake, take);
    }
    int deleteAndEarn(vector<int>& nums) {
         int maxVal = *max_element(nums.begin(), nums.end());
        vector<int> freq(maxVal + 1, 0);
        for (int num : nums) {
            freq[num] += num;
        }
        // for(int it: freq) cout << it <<" ";
        vector<int> dp(maxVal + 1, 0);
        // return solve(maxVal, nums, dp, freq);
        dp[1] = freq[1];
        for (int i = 2; i <= maxVal; i++) {
            dp[i] = max(dp[i-1], dp[i-2] + freq[i]);
        }
        return dp[maxVal];
    }
};