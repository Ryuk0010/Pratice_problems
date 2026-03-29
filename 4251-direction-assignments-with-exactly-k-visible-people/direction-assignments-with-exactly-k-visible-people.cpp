typedef long long ll;

const ll MOD=1e9+7;
class Solution {
public:
    ll power(ll base, ll exp){
        ll res = 1;
        base %= MOD;
        while(exp > 0){
            if(exp%2 == 1) res = (res*base) % MOD;
            base = (base*base)%MOD;
            exp /= 2;
        }
        return res;
    }
    ll modInv(ll n){
        return power(n, MOD-2);
    }
    ll nCr(int n, int k){
        if(k < 0 || k > n) return 0;
        if(k == 0 || k == n) return 1;
        if(k > n/2) k = n-k;

        ll num = 1, den = 1;
        for(int i = 0; i < k; i++){
            num = (num*(n-i))%MOD;
            den = (den*(i+1))%MOD;
        }
        return (num*modInv(den)) % MOD;
    }
    int countVisiblePeople(int n, int pos, int k) {
        return (nCr(n-1, k) * 2)%MOD;
    }
};