class Solution {
public:
    int solve(int mid, vector<int>& nums){
        int n = nums.size();
        int cnt=1;
        int pages = 0;
        for(int i = 0; i < n; i++){
            if(pages + nums[i] <= mid){
                pages += nums[i];
            }
            else{
                cnt++;
                pages = nums[i];
            }
        }
        return cnt;
    }
    int shipWithinDays(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int n = nums.size();
        int high = accumulate(nums.begin(), nums.end(), 0);
        while(low <= high){
            int mid = (low + high) / 2;
            if(solve(mid, nums) > k){   
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return low;
    }
};