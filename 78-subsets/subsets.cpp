class Solution {
public:
    void utility(int i, vector<int>& nums, vector<vector<int>>& ans, vector<int>& temp) {
        if (i==nums.size()) {
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        utility(i+1, nums, ans, temp);
        temp.pop_back();
        utility(i+1, nums, ans, temp);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>> ans;
       vector<int> temp;
       utility(0, nums, ans, temp);
       return ans;
    }
};