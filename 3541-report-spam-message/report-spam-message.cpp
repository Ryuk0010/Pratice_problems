class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        set<string> st(bannedWords.begin(), bannedWords.end());
        int cnt = 0;
        for(auto it: message){
            if(st.count(it)) cnt++;
            if(cnt >= 2) return true;
        }
        return false;
    }
};