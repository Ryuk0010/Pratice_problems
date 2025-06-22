class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> st(nums.begin(), nums.end());
        int n = nums.size();
        
        int ans = 0;
        int prev = *st.begin();
        int count = 0;
        for(auto it: st){
            if(abs(prev - it) <= 1){ 
                count++;
            }
            else count = 1;
            ans = max(ans, count);
            prev = it;
        }
        return ans;
    }
};