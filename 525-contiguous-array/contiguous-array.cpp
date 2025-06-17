class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mpp;
        int ans = 0;
        int n = nums.size();
        int sum = 0;
        mpp[0] = -1;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                sum -= 1;
            }
            else sum += 1;
            if(mpp.find(sum) != mpp.end()){
                ans = max(ans, i - mpp[sum]);
            }
            else mpp[sum] = i;
        }
        return ans;
    }
};