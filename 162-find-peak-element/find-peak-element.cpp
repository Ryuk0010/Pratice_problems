class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        int ind = -1;
        for(int i = 0; i < n; i++){
            bool graterThanLeft = (i == 0) || (nums[i] > nums[i-1]);
            bool graterThanRight = (i == n-1) || (nums[i] > nums[i+1]);
            int element = INT_MIN;
            if(graterThanLeft && graterThanRight){
                if(element < nums[i]){
                    element = nums[i];
                    ind = i;
                }
            }
        }
        return ind;
    }
};