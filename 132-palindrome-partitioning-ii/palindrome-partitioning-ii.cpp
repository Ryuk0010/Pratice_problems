class Solution {
int dp1[2000][2000];
    int dp2[2000];
    bool isPal(string &s, int i, int j) {
        if(i >= j)
            return true;

        if(dp1[i][j] != -1)
            return dp1[i][j];
            if(s[i] == s[j]) dp1[i][j] = isPal(s, i+1, j-1);
            else return false;
        return dp1[i][j];
    }
    int minCutHelp(string &s, int i) {
        if(i == s.length() - 1) 
            return 0;
        if(dp2[i] != -1)
            return dp2[i];
        
        dp2[i] = INT_MAX;

        if(isPal(s, i, s.length() - 1))
            return dp2[i] = 0;

        for(int k = i; k < s.length(); ++k) {
            if(!isPal(s, i, k))
                continue;
            dp2[i] = min(dp2[i], 1 + minCutHelp(s, k+1));
        }
        return dp2[i];
    }
public:
    int minCut(string s) {
        memset(dp1, -1, sizeof(dp1));
        memset(dp2, -1, sizeof(dp2));
        return minCutHelp(s, 0);
    }
};