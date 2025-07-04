class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<int> smallFromLeft(n, 0);
        int ans = -1;
        smallFromLeft[0] = 0;
        for(int i = 1; i < n; i++) {
            if(nums[i] < nums[smallFromLeft[i-1]]) smallFromLeft[i] = i;
            else smallFromLeft[i] = smallFromLeft[i-1];
        }
        int i = n-1;
        for(int j = n-1; j >= 0; j--) {
            while(i >= 0 && nums[smallFromLeft[i]] <= nums[j]){
                ans = max(ans, j - smallFromLeft[i]);
                i--;
            }
            
        }
        // for(int j = 0; j < n; j++) cout<<smallFromLeft[j]<<" ";
        return ans;
    }
};