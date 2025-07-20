class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> lMin(n), rMin(n);
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }   
            lMin[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        st = stack<int>();
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            rMin[i] = st.empty()? n: st.top();
            st.push(i);
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            int dist = rMin[i] - lMin[i] - 1;
            ans = max(ans, dist * heights[i]);
        }
        return ans;
    }
};