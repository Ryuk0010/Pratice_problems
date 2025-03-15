class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int,int> mpp;
        for(int it : nums) mpp[it]++;
        for(auto it : mpp) {
            if(k==0){
                if(it.second>1) ans++;
            } 
            else if(mpp.find(it.first + k) != mpp.end()) ans++;
        }
        return ans;
    }
};