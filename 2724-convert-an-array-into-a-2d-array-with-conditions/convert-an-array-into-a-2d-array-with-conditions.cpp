class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> mpp;
        
        int maxi = 0;
        for(auto it: nums){
            mpp[it]++;
            maxi = max(maxi,mpp[it]);

        }
        vector<vector<int>> ans(maxi);
        for(auto x : nums){
            mpp[x]-- ;
            int index = mpp[x] ;
            ans[index].push_back(x);
        }
        return ans;
    }
};