class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> ch(128, 0);
        int i = 0, cnt = 0;
        int n = s.size();
        for (int j = 0; j < n; j++) {
            while (ch[s[j]]) {
                ch[s[i]]--;
                i++;
            }
            ch[s[j]]++;
            cnt = max(cnt, j - i + 1);
        }
        return cnt;
    }
};
