class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> mpp;
        for(int i = 0; i+9 < s.size(); i++){
            mpp[s.substr(i, 10)]++;
        }
        vector<string> ans;
        for(auto it: mpp){
            if(it.second > 1) ans.push_back(it.first);
        }
        return ans;
    }
};