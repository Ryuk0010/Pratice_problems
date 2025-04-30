class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int firstMax = *max_element(nums.begin(), nums.end());
        int secMax = INT_MIN;
        int thiMax = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            if(secMax < nums[i] && nums[i] != firstMax){
                secMax = nums[i];
            }
        }
        int cnt = 0;
        if(secMax == INT_MIN) return firstMax;
        for(int i = 0; i < nums.size(); i++){
            if((thiMax < nums[i] || nums[i] == INT_MIN) && (nums[i] != secMax && nums[i] != firstMax)){
                thiMax = nums[i];
                cnt++;
            }
        }
        if(cnt == 0) return firstMax;
        return thiMax;
    }
};