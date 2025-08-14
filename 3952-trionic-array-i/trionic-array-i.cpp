class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if(n <= 3) return false;
        bool i1 = false;
        bool d = false;
        bool i2 = false;
        int i = 1;
        while(i < n && nums[i-1] < nums[i]){
            i++;
            i1 = true;
        }
        while(i < n && i1 && nums[i-1] > nums[i]){
            i++;
            d = true;
        }
        while(i < n && i1 && d && nums[i-1] < nums[i]){
            i++;
            i2 = true;
        }
        if(i == n) return (i1 && i2 && d) ? true: false;
        else return false;
        
    }
};