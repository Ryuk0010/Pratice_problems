class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, 0), right(n, 0);
        left[0] = nums[0];
        int cnt = 0;
        for(int i = 0; i < n; i++) if(nums[i] == 0) cnt++;
        // if(cnt >= 2) return 0;
        for(int i = 1; i < n; i++){
            left[i] = nums[i]*left[i-1];
        }
        right[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; i--){
            right[i] = nums[i]*right[i+1];
        }
        vector<int> ans;
        ans.push_back(right[1]);
        for(int i = 1; i < n-1; i++){
            ans.push_back(left[i-1]*right[i+1]);
        }
        ans.push_back(left[n-2]);
        return ans;
    }
};