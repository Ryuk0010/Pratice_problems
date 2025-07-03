class Solution {
public:
    int dp[1001][1001];
    bool solve(int i, int j, string& s){
        if(i >= j) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] != s[j]) return dp[i][j] = 0;

        return dp[i][j] = solve(i+1, j-1, s);
    }
    string longestPalindrome(string s) {
        memset(dp, -1, sizeof(dp));
        int n = s.length();
        int len = INT_MIN;
        int k = 0;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(solve(i, j, s)){
                    if(j-i+1 > len){
                        len = j-i+1;
                        k = i;
                    }
                }
            }
        }
        return s.substr(k, len);
    }
};