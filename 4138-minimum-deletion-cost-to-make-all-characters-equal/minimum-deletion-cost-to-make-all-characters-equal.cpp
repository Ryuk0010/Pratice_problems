#define ll long long
class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        vector<ll> c(26, 0);
        int n = s.length();
        ll tc = 0;
        ll mc = 0;
        for(int i = 0; i < n; i++){
            c[s[i] - 'a'] += cost[i];
            tc += cost[i];
        }
        for(auto it: c){
            mc = max(mc, it);
        }
        return tc - mc;
    }
};