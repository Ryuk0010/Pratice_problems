class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> st;
        int n = nums.size();
        for(auto& it: nums) st.insert(it);
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