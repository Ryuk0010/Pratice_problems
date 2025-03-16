class Solution {
public:
    int solve(int i, int j, vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& dp){
        if(i == nums1.size() || j == nums2.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        if(nums1[i] == nums2[j]) ans = 1 + solve(i+1, j+1, nums1, nums2, dp);

        return dp[i][j] = ans;
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int ans = 0;
        vector<vector<int>> dp(n, vector<int>(m, -1));

        // for(int i = 1; i <= n; i++){
        //     for(int j = 1; j <= m; j++){
        //         if(nums1[i-1] == nums2[j-1]){
        //             dp[i][j] = 1 + dp[i-1][j-1];
        //         }
        //         else{
        //             dp[i][j] = 0;
        //         }
        //         ans = max(ans, dp[i][j]);
        //     }
        // }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = max(ans, solve(i, j, nums1, nums2, dp));
            }
        }
    return ans;
    }
};