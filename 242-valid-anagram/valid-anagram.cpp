class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        unordered_map<char, int> mpp;
        for(auto it: s) mpp[it]++;
        for(int i = 0; i < t.length(); i++){
            if(mpp.find(t[i]) == mpp.end() || mpp[t[i]] == 0) return false;
            mpp[t[i]]--;
        }
        return true;
    }
};