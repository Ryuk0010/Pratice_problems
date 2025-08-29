class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        int n = nums.size();
        if(n%k) return false;
        int grp = n/k;
        for(int i = 0; i < n; i++){
            mpp[nums[i]]++;
            if(mpp[nums[i]] > grp) return false;
        }
        return true;
    }
};