class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        map<int, int> mpp;
        for(int i = 0; i < nums.size(); i++){
            mpp[nums[i]]++;
        }
        int ans = 0;
        for(auto it: mpp){
            if(it.second > 1){
                ans += (it.second - 1);
                mpp[it.first + 1] += it.second - 1;
            }
        }
        return ans;
    }
};