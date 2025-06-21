class Solution {
public:
    int rob(vector<int>& nums) {
        int l1 = 0;
        int l2 = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans = max(l2+nums[i], l1);
            l2 = l1;
            l1 = ans;
            
        }

        return ans;        
    }
};