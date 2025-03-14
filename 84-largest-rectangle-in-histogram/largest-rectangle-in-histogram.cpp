class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int ans = INT_MIN;
        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[i] < heights[st.top()]){
                int w;
                int hInd = st.top();
                st.pop();
                if(st.empty()) w = i;
                else w = i - st.top() - 1;
                ans = max(ans, heights[hInd] * w);
                
            }
            st.push(i);
        }
        while(!st.empty()){
            int w;
            int hInd = st.top();
            st.pop();
            if(st.empty()) w = n;
            else w = n - st.top() - 1;
            ans = max(ans, heights[hInd] * w);
        }
        return ans;
    }
};