class Solution {
public:
    vector<vector<int>> ck;
    int n, m;
    bool solve(int i, int j, vector<vector<char>>& board, string& word, int idx) {
        if (idx == word.size()) return true;
        if (i < 0 || j < 0 || i >= n || j >= m || board[i][j] != word[idx] || ck[i][j]) return false;

        ck[i][j] = 1;

        bool found = solve(i+1, j, board, word, idx+1) || solve(i-1, j, board, word, idx+1) || solve(i, j+1, board, word, idx+1) ||
            solve(i, j-1, board, word, idx+1);

        ck[i][j] = 0;
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        ck = vector<vector<int>>(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0] && solve(i, j, board, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};
