class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> temp(n, 0);
        int pf = 0;
        for(int i = 0; i < n; i++){
            pf += temp[i]; 
            nums[i] += pf; 
            // temp[i] = pf + nums[i];
            
            if(nums[i] < 0) return false;
            if(nums[i] == 0) continue;
            if(i+k > n) return false;
            // if(pf == 0) continue;
            pf -= nums[i];
            if(i+k < n)temp[i+k] += nums[i];
            
        }
        return true;
    }
};