class Solution {
    using ll = long long;
    vector<int> mid = {0, 1, 3, 5, 7, 9};
public:
    ll f(int n, ll x) {
        ll mn = 1e18;
        for(auto &o : mid) {
            if((o%2) != (n%2)) continue;
            if(o > n) break;
            string s(n, '0');
            if(o % 2) s[n/2] = (char)('0'+o);
            for(int bm = 0; bm < (1<<4); bm++) {
                vector<int> v;
                for(int i = 0; i < o/2; i++) v.push_back(o);
                for(int i = 0; i < 4; i++) {
                    if(bm & (1<<i)) {
                        for(int x = 0; x < i + 1; x++) v.push_back(2*(i+1));
                    }
                }
                if(v.size() != n/2) continue;
                sort(v.begin(), v.end());
                do {
                    for(int i = 0, j = n-1; i < n/2; i++, j--) {
                        s[i] = s[j] = ('0' + v[i]);
                    }
                    cout << s << "\n";
                    ll val = stoll(s);
                    if(val > x) mn = min(mn, val);
                }
                while(next_permutation(v.begin(), v.end()));
            }
        }
        return mn;
    }
    
    long long specialPalindrome(long long n) {
        int dig = to_string(n).size();
        return min(f(dig, n), f(dig+1, n));
    }
};