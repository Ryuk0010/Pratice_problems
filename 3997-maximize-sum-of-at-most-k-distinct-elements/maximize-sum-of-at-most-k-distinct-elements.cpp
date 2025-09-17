class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int prev = -1;
        for(int i = nums.size()-1; i >= 0; i--){
            if(k && prev != nums[i]) {
                ans.push_back(nums[i]);
                k--;
            }
            prev = nums[i];
        }
        return ans;
    }
};