class Solution {
public:
    void solve(int m, int n, string seq, vector<string>& ans){
        if(m == 0 && n == 0){
           ans.push_back(seq); 
           return;
        } 
        if(m == n){
            string seq1 = seq;
            seq1.push_back('(');
            solve(m-1, n, seq1, ans);
        }
        else if(m == 0){
            string seq1 = seq;
            seq1.push_back(')');
            solve(m, n-1, seq1, ans);
        }
        // else if(n == 0){
        //     string seq1 = seq;
        //     seq1.push_back('(');
        //     solve(m-1, n, seq1, ans);
        // }
        else{
            string seq1 = seq;
            string seq2 = seq;
            seq1.push_back('(');
            seq2.push_back(')');
            solve(m-1, n, seq1, ans);
            solve(m, n-1, seq2, ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string seq = "";
        solve(n, n, seq, ans);
        return ans;
    }
};