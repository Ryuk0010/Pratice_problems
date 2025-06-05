class Solution {
public:
    unordered_set<string> st;
    unordered_map<string, bool> dp;
    bool solve(string& w) {

        if(dp.find(w) != dp.end()) return dp[w];


        for(int i = 1; i < w.length(); i++) {
            string pre = w.substr(0, i);
            string suf = w.substr(i);
            if(st.count(pre) && (st.count(suf) || solve(suf))) return dp[w] = true;
        }
        return dp[w] = false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> res;

        for(auto w : words) st.insert(w);
        for(auto w : words) {
            if(solve(w)) res.push_back(w);
        }
        return res;
    }
};
