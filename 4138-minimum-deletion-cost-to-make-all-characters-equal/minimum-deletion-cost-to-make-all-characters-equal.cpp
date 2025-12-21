#define ll long long
class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        vector<ll> c(26, 0);
        int n = s.length();
        ll tc = 0, mc = 0;
        for(int i = 0; i < n; i++){
            c[s[i] - 'a'] += cost[i];
            tc += cost[i];
            mc = max(c[s[i] - 'a'], mc);
        }
        return tc - mc;
    }
};