class Solution {
public:
int result = 0;
    bool isPal(string& s){
        int i = 0, j = s.length()-1;
        while(i < j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void dfs(string& s, int ind, string &s1, string &s2){
        if(ind >= s.length()){
            if(isPal(s1) && isPal(s2)) result = max(result, (int)s1.length()*(int)s2.length());
            return;
        }

        s1.push_back(s[ind]);
        dfs(s, ind+1, s1, s2);
        s1.pop_back();

        s2.push_back(s[ind]);
        dfs(s, ind+1, s1, s2);
        s2.pop_back();

        dfs(s, ind+1, s1, s2);
    }
    int maxProduct(string s) {
        string s1 = "", s2 = "";
        dfs(s, 0, s1, s2);
        return result;
    }
};