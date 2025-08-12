class Solution {
public:
    bool solve(int ind, string s, unordered_set<string>& st, vector<int>& memo){
        if(ind == s.size()){
            return true;
        }
        if(memo[ind] != -1){
            return memo[ind];
        }
        for(int i = ind; i < s.length(); i++){
            if(st.count(s.substr(ind, i-ind+1)) && solve(i+1, s, st, memo)){
                return memo[ind] = true;
            }
        }
        return memo[ind] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> memo(s.size(), -1);
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        return solve(0, s, st, memo);
    }
};