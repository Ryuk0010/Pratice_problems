class Solution {
    public:
    vector<vector<int>> ans;
    void subsetsHelper(vector<int>& nums, int i, vector<int> subset) {
        if(i == nums.size()) {  
            ans.push_back(subset);
            return;
        }
        subsetsHelper(nums, i+1, subset);
        subset.push_back(nums[i]);
        subsetsHelper(nums, i+1, subset);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        subsetsHelper(nums, 0, subset);
        return ans;
    }
};