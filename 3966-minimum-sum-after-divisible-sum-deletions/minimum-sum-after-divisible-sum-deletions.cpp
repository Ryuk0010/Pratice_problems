class Solution {
    using ll = long long;
public:
    ll minArraySum(vector<int>& nums, int k) {
        int n = nums.size();

        vector<ll> best(k, -LLONG_MAX); best[0] = 0;
        vector<ll> dp(n, 0), pref(n, 0);
        for(int i = 0; i < n; i++) {
            pref[i] += nums[i];
            if(i) dp[i] = dp[i-1], pref[i] += pref[i-1];
            
            if(best[pref[i] % k] != -LLONG_MAX) {
                dp[i] = max(dp[i], pref[i] + best[pref[i] % k]);
            }
            best[pref[i] % k] = max(best[pref[i] % k], dp[i] - pref[i]);
        }

        ll tot = 0;
        for(auto &x : nums) tot += x;
        return tot - dp[n-1];
    }
};