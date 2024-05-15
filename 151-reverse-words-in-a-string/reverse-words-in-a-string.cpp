class Solution {
public:
    string reverseWords(string s) {
        string ans;
        int n = s.length();
        int i = 0;
        while (i < n) {
            string st = "";
            while (i < n && s[i] == ' ') {
                i++;
                if (i >= n) {
                    break;
                }
            }
            int j = i;
            while (j < n && s[j] != ' ') {
                st += s[j++];
            }
            if (st.length() > 0) {

                if (ans.length() == 0) {
                    ans = st;
                } else {
                    ans = st + " " + ans;
                }
                i = j + 1;
            }
        }
        return ans;
    }
};