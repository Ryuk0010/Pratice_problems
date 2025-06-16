class Solution {
public:
    void dfs(string& digits, int i, vector<string>& m, vector<string>& res, string& cur) {
        if (i == digits.size()) {
            res.push_back(cur);
            return;
        }
        for (char c : m[digits[i] - '0']) {
            cur.push_back(c);
            dfs(digits, i + 1, m, res, cur);
            cur.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> res;
        vector<string> m = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string cur;
        dfs(digits, 0, m, res, cur);
        return res;
    }
};
