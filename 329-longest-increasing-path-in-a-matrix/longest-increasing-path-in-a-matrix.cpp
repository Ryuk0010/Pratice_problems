class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        int node = matrix[i][j];
        int arrX[] = {1, -1, 0, 0};
        int arrY[] = {0, 0, 1, -1};
        int ans = 0;
        if(dp[i][j] != -1) return dp[i][j];
        for(int a = 0; a < 4; a++){
            int ni = arrX[a] + i;
            int nj = arrY[a] + j;
            if(ni >= 0 && ni < matrix.size() && nj >= 0 && nj < matrix[0].size()){
                if(matrix[ni][nj] > node) ans = max(ans, dfs(ni, nj, matrix, dp));
            }
        }
        return dp[i][j] = ans+1;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(dp[i][j] == -1)dp[i][j] = dfs(i, j, matrix, dp);
            }
        }
        int ans = INT_MIN;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                cout << dp[i][j] << " ";
                ans = max(dp[i][j], ans);
            }
            cout << endl;
        }
        return ans;
    }
};