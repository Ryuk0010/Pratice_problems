class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        stack<int> st;
        vector<int> ans(nums.size(), 0);
        st.push(0);
        int sum = 0;
        for(int i = nums.size() - 1; i > 0; i--){
            st.push(sum += nums[i]);
        }
        ans[0] = st.top();
        st.pop();
        sum = 0;
        for(int i = 0; i < nums.size()-1; i++){
            ans[i+1] = abs((sum += nums[i]) - st.top());
            st.pop();
        }
    return ans;
    }
};