class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.size();
        vector<int> dp(n+1, -1); dp[0] = 0;

        set<int> evens, odds;
        for(int i = 2; i <= n; i+=2) evens.insert(i);
        for(int i = 1; i <= n; i+=2) odds.insert(i);
        
        queue<int> q; q.push(0);
        while(!q.empty()) {
            int x = q.front(); q.pop();
            int start = x + k - 2*min(k, x), end = x + k - 2*max(k-(n-x), 0);
            auto it_s = (start % 2 ? odds.lower_bound(start) : evens.lower_bound(start));
            auto it_e = (start % 2 ? odds.upper_bound(end) : evens.upper_bound(end));
            while(it_s != it_e) {
                int y = *(it_s);
                if(dp[y] == -1) {
                    dp[y] = dp[x] + 1;
                    q.push(y);
                }
                if(start % 2) odds.erase(it_s++);
                else evens.erase(it_s++);
            }
        }

        int cnt = 0;
        for(auto x : s) if(x == '0') cnt++;
        return dp[cnt];
    }
};