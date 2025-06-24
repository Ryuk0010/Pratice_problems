class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int t) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();

        for(int i = 0; i <= n-4; i++){   // i == 0
            if(i > 0  && nums[i] == nums[i-1]) continue;
            for(int j = i+1; j <= n-3; j++){  // j=1
                if(j > i+1 && nums[j] == nums[j-1]) continue;
                long long target = (long long)t - nums[i] - nums[j]; //tar = 0

            int k = j+1, l = n-1;// k=2, l=4
                while(k < l){
                    long long sum = nums[k] + nums[l];
                    if(sum == target){

                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        l--;
                        while(k < l && nums[k] == nums[k-1]) k++;
                        while(l > k && nums[l] == nums[l+1]) l--;
                    }
                    else if(sum > target){
                        l--;
                    }
                    else k++;
                }
            }
            
        }
        return ans;
    }
};