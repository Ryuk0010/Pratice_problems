class Solution {
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        const int MOD = 1e9+7;

        int p1 = 0, p2 = 0;
        long long ans = 0;

        for (int x : nums) {
            if (x < a) {
                ans = (ans + p1 + p2) % MOD;
            }
            else if (x <= b) {
                ans = (ans + p2) % MOD;
                p1++;
            }
            else {
                p2++;
            }
        }

        return ans;
    }
};