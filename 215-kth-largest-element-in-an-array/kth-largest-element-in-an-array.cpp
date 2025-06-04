class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        map<int, int, greater<int>> mpp;
        for(int i = 0; i < nums.size(); i++){
            mpp[nums[i]]++;
        }
        int freq = 0;
        for(auto it: mpp){
            freq = it.second;
            while(freq){
                freq--;
                k--;
                if(k == 0) return it.first;
            }
            
        }
        return 0;
    }
};