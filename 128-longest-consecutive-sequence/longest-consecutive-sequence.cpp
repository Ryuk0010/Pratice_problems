class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int ans = 0;
        for(auto& it: st){
            int ele = it;
            if(!st.count(ele-1)){
                int curr = ele;
                int cnt = 1;
                while(st.count(curr+1)){
                    curr++;
                    cnt++;
                }
                ans = max(ans, cnt);
            }
            
        }
        return ans;
    }
};