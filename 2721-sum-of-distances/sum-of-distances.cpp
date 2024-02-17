class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<long long, vector<long long>> mpp;
        vector<long long> ans(nums.size(), 0);
        for(int i = 0; i < nums.size(); i++){
            mpp[nums[i]].push_back(i);
        }
        for(auto it: mpp){
            vector<long long> arr = it.second;
            long long sum = 0;
            for(auto k: arr) sum += k;
            
            long long cursum = 0, restsum = 0;
            for(int i = 0; i < arr.size(); i++){
                restsum = sum - cursum - arr[i];
                long long before = arr[i]*i - cursum;
                long long after = restsum - arr[i] * ((long long)(arr.size()-i-1));
                ans[arr[i]] = before + after;
                cursum += arr[i];
            }
        }
        return ans;
    }
};