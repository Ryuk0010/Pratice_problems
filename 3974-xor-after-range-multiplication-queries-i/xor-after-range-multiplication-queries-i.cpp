class Solution {
public:
    const int MOD = 1e9 + 7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        long long ans = 0;
        vector<long long> arr(nums.begin(), nums.end());
        for(auto it: queries){
            int l = it[0];
            int r = it[1];
            int k = it[2];
            int v = it[3];
            for(int i = l; i <= r; i+=k){
                arr[i] = (arr[i]*v) % MOD;
            }
        }
        ans = arr[0];
        for(int i = 1; i < n; i++){
            ans ^= arr[i];
        }
    return ans;
    }
};