class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int l = 0;
        int n = nums.size();
        int count = 0;
        for(int r = 0; r < n; r++) {
            if(nums[r] % k != 0) continue;
            int num = nums[r];
            for(int l = r; l >= 0; l--) {
                if(r == l && nums[r] == k) {
                    count++;
                    continue;
                }
                num = gcd(nums[l], num);
                if(num == k) count++;
            }
        }
        return count;
    }
};