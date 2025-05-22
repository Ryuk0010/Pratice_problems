class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        vector<int> arr;
        for(int i = 0; i < nums.size(); i++){
            int ele = nums[i];
            int sum = 0;
            while(ele > 0){
                sum += ele%10;
                ele /= 10;
            }
            if(sum == i) return i;
        }
        return -1;
    }
};