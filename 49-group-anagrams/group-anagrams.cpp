class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mpp;
        vector<vector<string>> ans;
        for(auto it: strs){
            string temp = it;
            sort(it.begin(), it.end());
            mpp[it].push_back(temp);
        }
        for(auto it: mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};