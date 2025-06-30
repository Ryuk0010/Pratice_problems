class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, int> mpp;
        long long gp = 0;
        int n = nums.size();
        long long pairs = (1LL * (n - 1) * n) / 2;
        for(int i = 0; i < nums.size(); i++) nums[i] = nums[i] - i;
        for(int i = 0; i < nums.size(); i++){
            gp += mpp[nums[i]];
            mpp[nums[i]]++;
        }
        return pairs - gp;
    }
};