class Solution {
public:
    int solve(vector<vector<char>>& matrix, int i, int j, vector<vector<int>> & dp){
        if(i >= matrix.size() || j >= matrix[0].size() || matrix[i][j] == '0') return 0;

        if(dp[i][j] != -1) return dp[i][j];
        int right = solve(matrix, i, j+1, dp);
        int down = solve(matrix, i+1, j, dp);
        int rw = solve(matrix, i+1, j+1, dp);

        return dp[i][j] = 1 + min({right, down, rw});
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j]) ans = max (ans, solve(matrix, i, j, dp));
            }
        }
        return ans*ans;
    }
};