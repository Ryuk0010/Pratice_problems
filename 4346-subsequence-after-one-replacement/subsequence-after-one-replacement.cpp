class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        if(s.length()>t.length())return false;
        int n = s.size();
        int m = t.size();
        if(n==0)return true;
        vector<int>pre(n, -1);
        vector<int>suf(n, -1);
        int j=0;
        for(int i = 0; i < n; i++){
            while(j < m && s[i] != t[j]) j++;
            if(j == m) break;
            pre[i] = j++;
        }
        j = m-1;
        for(int i = n-1; i >= 0; i--){
            while(j >= 0 && s[i] != t[j]) j--;
            if(j < 0) break;
            suf[i] = j--;
        }
        for(int i = 0; i < n; i++){
            if((i == 0 || pre[i-1] != -1) && (i == n-1 || suf[i+1] != -1)){
                int l = (i==0)?-1:pre[i-1];
                int r = (i==n-1)?m:suf[i+1];
                if(l+1 < r) return true;
            }
        }
        return false;
    }
};