class Solution {
public:
    bool isSafe(int a, int b, vector<string>& cb, int n){
        int i = a;
        int j = b;
        //up
        while(i >= 0){
            if(cb[i][j] == 'Q') return false;
            i--;
        }
        //left
        i = a, j = b;
        while(i >= 0 && j >= 0){
            if(cb[i][j] == 'Q') return false;
            i--;
            j--;
        }
        //right
        i = a, j = b;
        while(i >= 0 && j < n){
            if(cb[i][j] == 'Q') return false;
            i--;
            j++;
        }
        return true;
    }
    void helperSolveNQueen(int i, vector<string>& cb, int n, vector<vector<string>>& ans){
        if(i == n){
            ans.push_back(cb);
            return;
        }

        for(int j = 0; j < n; j++){
            if(isSafe(i, j, cb, n)){
                cb[i][j] = 'Q';
                helperSolveNQueen(i+1, cb, n, ans);
                cb[i][j] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        string row(n, '.');
        vector<string> cb(n, row);
        vector<vector<string>> ans;
        helperSolveNQueen(0, cb, n, ans);
        return ans;
    }
};