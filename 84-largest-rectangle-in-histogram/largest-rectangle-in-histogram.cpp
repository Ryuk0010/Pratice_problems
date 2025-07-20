class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        int n = heights.size();
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                int ele = heights[st.top()];
                st.pop();
                int left = st.empty() ? -1 : st.top();
                ans = max(ans, ele * (i - left - 1));
            }
            st.push(i);
        }
        while(!st.empty()){
            int ele = heights[st.top()];
            st.pop();
            int left = !st.empty() ? st.top() : -1;
            ans = max(ans, ele * (n - left - 1));
        }
        return ans;
    }
};