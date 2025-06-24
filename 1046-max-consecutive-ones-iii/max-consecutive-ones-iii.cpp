class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0, j;
        int ans = 0;
        for (j = 0; j < nums.size(); j++) {
            if (nums[j] == 0) k--;

            if (k < 0) {
                if (nums[i] == 0) k++;
                i++;
            }
        }
        return j - i;
    }
};