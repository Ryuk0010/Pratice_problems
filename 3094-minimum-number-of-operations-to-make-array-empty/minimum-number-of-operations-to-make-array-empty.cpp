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
            int rem = 0;
            if(a == 1) return -1;
            if(a % 3 == 0){
                op += a/ 3;
            }
            else if(a % 3 == 1){
                a -= 4;
                op += a / 3;
                op += 2;
            }
            else if(a % 3 == 2){
                a -= 2;
                op += a / 3;
                op += 1;
            }  
        }
        return op;
    

    }
};