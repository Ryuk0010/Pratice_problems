class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for(char digit: num){
            while(!st.empty() && k > 0 && st.top() > digit){
                st.pop();
                k--;
            }
            st.push(digit);
        }
        while(k && !st.empty()){
            st.pop();
            k--;
        }

        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        int i = 0;
        while(ans[i] == '0' && i < ans.size())i++;
        if(i == ans.size()) return "0";

        return ans.substr(i);
    }
};