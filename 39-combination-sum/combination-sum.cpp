class Solution {
public:
    void solve(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int> temp, int ind){
        if(target < 0) return;
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        if (ind >= candidates.size()) return;
        solve(candidates, target, ans, temp, ind+1);
        temp.push_back(candidates[ind]);
        solve(candidates, target - candidates[ind], ans, temp, ind);
        temp.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(candidates, target, ans, temp, 0);
        return ans;
    }
};