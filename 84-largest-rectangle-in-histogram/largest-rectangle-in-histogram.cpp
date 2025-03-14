class Solution {
public:
    
    vector<int> nextNse(vector<int>& heights){
        stack<int> st;
        int n = heights.size();
        vector<int> ans(n, n);
        
        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                ans[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
    

    vector<int> prevPse(vector<int>& heights){
        stack<int> st;
        int n = heights.size();
        vector<int> ans(n, -1);
        
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && heights[st.top()] > heights[i]){
                ans[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> nse = nextNse(heights);
        vector<int> pse = prevPse(heights);

        int ans = INT_MIN;
        for(int i = 0; i < heights.size(); i++){
            int w = nse[i] - pse[i] - 1;
            ans = max(ans, w*heights[i]);
        }
        return ans;
    }
};