class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        auto itr = remove_if(nums.begin(), nums.end(), [](auto x){
            return x < 0;
        });
        nums.erase(itr, nums.end());

        if(nums.size() < 1) return 1;

        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int ans = 1;
        for(int i = 0; i < n; i++){
            if(nums[i] == ans) ans++;
            else if(nums[i] > ans) return ans;
        }
        return nums[n-1]+1;
    }
};