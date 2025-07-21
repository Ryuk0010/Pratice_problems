class Solution {
public:
    int hist(vector<int>& height){
        int n = height.size();
        stack<int> st;
        int ans = 0;
        for(int i = 0 ; i < n; i++){
            while(!st.empty() && height[st.top()] > height[i]){
                int ele = st.top();
                st.pop();
                int left = !st.empty() ? st.top() : -1;
                ans = max(ans, height[ele] * (i - left - 1));
            }
            st.push(i);
        }

        while(!st.empty()){
            int ele = st.top();
            st.pop();
            int left = !st.empty() ? st.top() : -1;
            ans = max(ans, height[ele] * (n - left - 1));
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> height(m, 0);
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == '1'){
                    height[j] += 1;
                }
                else height[j] = 0;
            }
            ans = max(ans, hist(height));
        }
        return ans;
    }
};