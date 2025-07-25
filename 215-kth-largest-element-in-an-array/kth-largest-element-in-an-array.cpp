class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        map<int, int> mpp;
        k = nums.size() - k + 1;
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
// 1 - 1
// 2 - 2
// 3 - 2
// 4 - 1
// 5 - 2
// 6 - 1

