class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int k = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != i) k &= nums[i];
        }
        return (k == INT_MAX) ? 0 : k;
    }
};