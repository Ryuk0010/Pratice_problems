class Solution {
public:
    int solve(int i, int j, vector<int>& nums, vector<vector<int>>& dp){
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        for(int k = i; k <= j; k++){
            int sum = nums[i-1]*nums[k]*nums[j+1] + solve(i, k-1, nums, dp) + solve(k+1, j, nums, dp);
            ans = max(sum, ans); 
        }
        return dp[i][j] = ans;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int ans = solve(1, nums.size()-2, nums, dp);
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < n; j++){
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return ans;
    }
};