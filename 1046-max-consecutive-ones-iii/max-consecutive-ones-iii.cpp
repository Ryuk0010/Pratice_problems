class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0, ans = 0;
        int cnt = 0;
        int n = nums.size();
        for(int j = 0; j < n; j++){
            if(nums[j] == 0) cnt++;
            while(cnt > k){
                if(nums[i] == 0) cnt--;
                i++;
            }
            ans = max(j - i + 1, ans);
        }
        return ans;
    }
};