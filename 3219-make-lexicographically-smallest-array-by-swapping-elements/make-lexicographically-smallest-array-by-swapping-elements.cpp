class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<pair<int, int>> ele;
        int n = nums.size();
        for(int i = 0; i < n; i++)ele.push_back({nums[i], i});
        sort(ele.begin(), ele.end());

        vector<vector<pair<int, int>>> indPair;
        indPair.push_back({ele[0]});
        for(int i = 1; i < n; i++){
            if(ele[i].first - ele[i-1].first <= limit) indPair.back().push_back({ele[i]});
            else indPair.push_back({ele[i]});
        }


        vector<int> ans(n, 0);
        for(auto& it: indPair){
            vector<int> idx;
            for(auto [value, index]: it){
                idx.push_back(index);
            }
            sort(idx.begin(), idx.end());

            for(int i = 0; i < idx.size(); i++){
                ans[idx[i]] = it[i].first;
            }

        }
        return ans;
    }
};