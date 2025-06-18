class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> arr(n, 0);
        int ps = 0;
        for(int i = 0; i < n; i++){
            ps += arr[i];
            nums[i] += ps;

            if(nums[i] < 0) return false;
            if(nums[i] == 0) continue;
            if(i + k > n) return false;
            

            ps -= nums[i];
            if(i+k < n)arr[i+k] += nums[i];

        }
        return true;
    }
};