class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        for(auto &it: nums) mpp[it]++;
        int n = nums.size();
        if(n%k) return false;
        int g = n/k;
        for(auto &it: mpp){
            if(it.second > g) return false;
        }
        return true;
    }
};