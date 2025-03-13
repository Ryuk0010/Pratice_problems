class Solution {
public:
    int dp[500];
    int solve(int i, int k, vector<int>& arr){
        if(i == arr.size()) return 0;
        if(dp[i] != -1) return dp[i];

        int ans = INT_MIN;
        int len = 0;
        int mx = INT_MIN;
        for(int j = i; j < min(i+k, (int)arr.size()); j++){
            len++;
            mx = max(mx, arr[j]);
            ans = max(ans, solve(j+1, k, arr) + mx*len); 
        }
        return dp[i] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp, -1, sizeof(dp));
        return solve(0, k, arr);
    }
};