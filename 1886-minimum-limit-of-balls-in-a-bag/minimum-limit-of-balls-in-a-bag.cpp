class Solution {
public:
    int isPoss(vector<int>& nums, int maxball, int maxOperations){
        int totOprn = 0;
        for(int &num: nums){
            int oprn = num / maxball;
            if(!(num % maxball)) oprn--;
            totOprn += oprn;
        }
        return totOprn <= maxOperations;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1, right = *max_element(nums.begin(), nums.end());
        int ans = right;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(isPoss(nums, mid, maxOperations)){
                ans = mid; 
                right = mid - 1;
            }
            else left = mid + 1;
        }
        return ans;
    }
};