class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int lo = -1;
        int lt = -1;
        int mindiff = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1){
                lo = i;
                if(lt != -1) mindiff = min(mindiff, abs(i - lt));
            }
            if(nums[i] == 2){
                lt = i;
                if(lo != -1) mindiff = min(mindiff, abs(lo - i));
            }
        } 
        return mindiff == INT_MAX ? -1: mindiff;
    }
};