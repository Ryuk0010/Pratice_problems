class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int opened = 0;

        for (char c : s) {
            if (c == '(') {
                opened++;
                ans = max(ans, opened);
            } else if (c == ')') {
                opened--;
            }
        }

        return ans;
    }
};