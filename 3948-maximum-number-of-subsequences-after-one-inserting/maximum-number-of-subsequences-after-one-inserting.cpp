class Solution {
    using ll = long long;
public:
    long long numOfSubsequences(string s) {
        int n = s.size();
        vector<int> pref_l(n,0), suff_t(n,0);
        for(int i = 0; i < n; i++) {
            if(i) pref_l[i] += pref_l[i-1];
            if(s[i] == 'L') pref_l[i]++;
        }
        for(int i = n-1; i >= 0; i--) {
            if(i+1 < n) suff_t[i] += suff_t[i+1];
            if(s[i] == 'T') suff_t[i]++;
        }
        ll ans = 0, best = 0, ansl = 0, anst = 0;
        ll res = 0;
        for(int i = 0; i < n; i++) {
            ll p = pref_l[i];
            ll sf = suff_t[i];
            if(s[i] == 'C') ans += p*sf;

            if(s[i] == 'C') ansl += (p+1)*sf;

            if(s[i] == 'C') anst += p*(sf+1);

            best = max(best, p*sf);
            res = max({res, ans+best, ansl, anst});
        }
        return res;
    }
};