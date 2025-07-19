class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        stack<int> st;
        int water = 0;
        
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && height[i] >= height[st.top()]) {
                int top = st.top();
                st.pop();
                if (st.empty()) break;

                int distance = i - st.top() - 1;
                int boundedHeight = min(height[i], height[st.top()]) - height[top];
                water += distance * boundedHeight;
            }
            st.push(i);
        }
        
        return water;
    }
};
