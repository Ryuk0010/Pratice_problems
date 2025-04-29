class Solution {
public:
    #define ll long long
    long long countSubarrays(vector<int>& nums, long long k) {
        ll ans = 0;
        int j = 0;
        ll sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            while(sum * (i-j+1) >= k){
                sum -= nums[j++];
            }
            ans += i-j+1;
        }
        return ans;
    }
};