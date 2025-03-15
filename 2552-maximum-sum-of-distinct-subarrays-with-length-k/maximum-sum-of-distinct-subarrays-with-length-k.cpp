class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long curr_sum = 0;
        long long ans=0;
        int j = 0;
        unordered_set<int> st;
        for(int i = 0; i < n; i++){
            if(st.find(nums[i]) == st.end()){
                st.insert(nums[i]);
                curr_sum += nums[i];
                if(i - j + 1 == k){
                    ans = max(ans, curr_sum);
                    curr_sum -= nums[j];
                    st.erase(nums[j]);
                    j++;
                }
            }
            else{
                while(nums[j] != nums[i]){
                    st.erase(nums[j]);
                    curr_sum -= nums[j];
                    j++;
                }
                j++;
            }
        }
        return ans;
    }
};