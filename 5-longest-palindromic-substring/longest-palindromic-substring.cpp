class Solution {
public:
    int dp[1001][1001];
    bool solve(int i, int j, string& s){
        if(i >= j) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] != s[j])  return dp[i][j] = 0;
        return dp[i][j] = solve(i+1, j-1, s);
    }
    string longestPalindrome(string s) {
        memset(dp, -1, sizeof(dp));
        int n = s.length();
        int len = -1;
        int a = 0;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(solve(i, j, s)){
                    if(len < j-i+1){
                        len = j-i+1;
                        a = i;
                    }
                }
            }
        }
        return s.substr(a, len);
    }
};