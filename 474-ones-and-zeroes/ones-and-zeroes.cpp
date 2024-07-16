class Solution {
public:
    vector<vector<vector<int>>> dp;
    int fun(int i, int m, int n, vector<pair<int, int>>& v){
        if(i<0) return 0;
        if(dp[i][m][n]!=-1) return dp[i][m][n];
        if(m>=v[i].first && n>=v[i].second) return dp[i][m][n] = max(1+fun(i-1, m-v[i].first, n-v[i].second, v), fun(i-1, m, n, v));
        return dp[i][m][n] = fun(i-1, m, n, v);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        dp.resize(strs.size()+1, vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        vector<pair<int, int>> v;
        for(string x : strs){
            int cnt = count(x.begin(), x.end(), '0');
            v.push_back({cnt, x.size()-cnt});
        }
        return fun(strs.size()-1, m, n, v);
    }
};