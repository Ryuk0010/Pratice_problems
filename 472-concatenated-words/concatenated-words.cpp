class Solution {
public:
    vector<string> ans;
    unordered_set<string> st;
    unordered_map<string, bool> dp;
    bool solve(string& s){

        if(dp.find(s) != dp.end()) return dp[s];
        for(int i = 1; i < s.length(); i++){
            string pre = s.substr(0, i);
            string suf = s.substr(i);

            if(st.count(pre) && (st.count(suf) || solve(suf))) return dp[s] = true;
            
        }
        return dp[s] = false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        
        for(auto it: words) st.insert(it);
        for(auto it: words){ 
            if(solve(it)) ans.push_back(it);
        }
        return ans;
    }
};