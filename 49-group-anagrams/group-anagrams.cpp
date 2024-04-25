class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        
        for(auto x: strs){
            string word = x;
            sort(word.begin(), word.end());
            cout << word << " " << x << endl;
            mp[word].push_back(x);
            //cout << mp.first <<" " << mp.second;
        }
        
        vector<vector<string>> ans;
        for(auto x: mp){
            ans.push_back(x.second);
        }
        return ans;
    }
};