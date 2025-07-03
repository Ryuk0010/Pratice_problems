class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int curr;
        int ans = 0, cnt = 0;;
        for(auto it: st){
            curr = it;
            if(st.count(curr-1)) continue;
            cnt = 1;
            while(st.count(curr+1)){
                curr = curr+1;
                cnt++;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};