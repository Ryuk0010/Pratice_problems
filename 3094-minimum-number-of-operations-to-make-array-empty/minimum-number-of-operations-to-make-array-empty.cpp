class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for(auto it: nums){
            mpp[it]++;
        }
        int op = 0;
        for(auto it: mpp){
            int a = it.second;
            if(a == 1) return -1;
            op += (a + 2)/3;
        }
        return op;
    

    }
};