class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.empty()) return ans;

        unordered_map<char, string> mp = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };

        dfs(digits, 0, "", ans, mp);
        return ans;
    }

    void dfs(string digits, int i, string cur, vector<string>& ans, const unordered_map<char, string>& mp) {
        if (i == digits.size()) {
            ans.push_back(cur);
            return;
        }

        for (char ch : mp.at(digits[i])) {
            dfs(digits, i + 1, cur + ch, ans, mp);
        }
    }
};
