class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        int ind = 0;
        int  count = 0;
        while(ind+1 < nums.size() && nums[ind] < nums[ind+1]) ind++;
        if(ind == nums.size() - 1) return 0;

        ind++;
        int pivot = ind;
        while(ind + 1 < nums.size() && nums[ind] < nums[ind + 1]) ind++;
        if(ind != nums.size() - 1) return -1;
        if(nums[pivot] < nums[0] && nums[nums.size() - 1] < nums[0]){
            return nums.size() - pivot;
        }
        else{
            return -1;
        }
    }
};