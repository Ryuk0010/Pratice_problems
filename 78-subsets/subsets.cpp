class Solution {
public:
    vector<vector<int>> fn(vector<int>& nums, int i){
        if(i == nums.size()) return {{}};
        vector<vector<int>> ans;
        vector<vector<int>> t = fn(nums, i+1);
        for(auto it: t){
            ans.push_back(it);
        }
        for(auto it: t){
            it.push_back(nums[i]);
            ans.push_back(it);
        }
        return ans;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        return fn(nums, 0);
    }
};