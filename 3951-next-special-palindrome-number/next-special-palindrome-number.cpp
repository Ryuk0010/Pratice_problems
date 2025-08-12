class Solution {
    using ll = long long;
    vector<int> mid = {0, 1, 3, 5, 7, 9};
public:
    ll solve(int dig, ll n) {
        ll ans = 1e18;
        for(auto odd: mid){
            if((odd%2) != (dig%2)) continue;
            if(odd > dig) break;
            string s(dig, '0');
            if(odd%2) s[dig/2] = ('0'+odd);
            for(int m = 0; m < (1 << 4); m++){
                vector<int> v;
                for(int i = 0; i < odd/2; i++) v.push_back(odd);
                for(int i = 0; i < 4; i++){
                    if(m & (1 << i)){
                        for(int j = 0; j < i+1; j++) v.push_back(2*(i+1));
                    }
                }

                if(v.size() != dig/2) continue;
                sort(v.begin(), v.end());
                do{
                    for(int i = 0, j = dig-1; i < dig/2; i++, j--){
                        s[i] = ('0' + v[i]);
                        s[j] = ('0' + v[i]);
                    }
                    ll val = stoll(s);
                    if(val > n) {ans = min(val, ans); break;}
                }
                while(next_permutation(v.begin(), v.end()));

            }
            
        }
        return ans;
    }
    
    long long specialPalindrome(long long n) {
        int dig = to_string(n).size();
        return min(solve(dig, n), solve(dig+1, n));
    }
};