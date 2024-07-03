class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int ans = 0;
        st.push(-1);
        for(int i = 0; i < s.length(); i++){
            char c = s[i];
            if(c == '(') st.push(i);
            else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }
                else{
                    int len = i - st.top();
                    ans = max(ans, len);
                }
            }
        }
        return ans;
    }
};