class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.length();
        vector<int> ps(n, 0);
        vector<int> l(n, -1), r(n, -1);
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '*') ++cnt;
            ps[i] = cnt;
        }
        int prev = -1;
        for(int i = 0; i < n; i++){
            if(s[i] == '|') prev = i;
            l[i] = prev;
        }
        int next = -1;
        for(int i = n-1; i >= 0; i--){
            if(s[i] == '|') next = i;
            r[i] = next;
        }
        vector<int> ans;
        for(int i = 0; i < queries.size(); i++){
            int c1 = r[queries[i][0]];
            int c2 = l[queries[i][1]];
            if(c1 > -1 && c2 > -1 && c1 < c2) ans.push_back(ps[c2]-ps[c1]);
            else ans.push_back(0);
        }
        return ans;
    }
};