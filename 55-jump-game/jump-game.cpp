class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1) return true;
        int s = nums[0];
        for(int i = 0; i < nums.size(); i++){
            if(s >= nums.size()-1) return true;
            if(nums[i] == 0 && s <= i) return false;
            s = max(s, i + nums[i]);
        }
        return false;
    }
};