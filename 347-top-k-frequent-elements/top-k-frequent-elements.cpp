class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        vector<vector<int>> bucket(n+1);
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++) mpp[nums[i]]++;
        for(auto it: mpp){
            bucket[it.second].push_back(it.first);
        }
        for(int i = n; i >= 0; i--){
            if(bucket[i].size() == 0) continue;
            while(bucket[i].size() > 0 && k > 0){
                ans.push_back(bucket[i].back());
                bucket[i].pop_back();
                k--;
            }
        }
        return ans;
    }
};