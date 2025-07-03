class Solution {
public:
    void solve(int n, int m, string seq, vector<string>& ans){
        if(m == 0 && n == 0) ans.push_back(seq);
        else if(m == n){
            seq.push_back('(');
            solve(n-1, m, seq, ans);
        }
        else if(n == 0){
            seq.push_back(')');
            solve(n, m-1, seq, ans);
        }
        else{
            seq.push_back('(');
            solve(n-1, m, seq, ans);
            seq.pop_back();
            seq.push_back(')');
            solve(n, m-1, seq, ans);
        }

    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(n, n, "", ans);
        return ans;
    }
};