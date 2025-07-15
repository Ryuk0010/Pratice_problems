class Solution {
public:
    int findPal(string s, int l, int r) {
        int cnt = 0;
        while (l >= 0 && r < s.length() && s[l] == s[r]) {
            cnt++;
            l--;
            r++;
        }
        return cnt;
    }

    int countSubstrings(string s) {
        int ans = 0;

        for (int i = 0; i < s.length(); i++) {
            ans += findPal(s, i, i + 1);
            ans += findPal(s, i, i);
            
        }
        return ans;        
    }
};