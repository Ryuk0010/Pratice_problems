class Solution {
public:
    void gameOfLife(vector<vector<int>>& b) {
        int r = b.size(), c = b[0].size();
        vector<vector<int>> ans(r, vector<int>(c));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
                int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

                int o = 0, z = 0;
                for (int idx = 0; idx < 8; idx++) {
                    int nx = i + dx[idx], ny = j + dy[idx];
                    if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                    b[nx][ny] == 1 ? o++ : z++;
                }

                if (b[i][j] == 1 && o < 2) ans[i][j] = 0;
                else if (b[i][j] == 1 && (o == 2 || o == 3)) ans[i][j] = 1;
                else if (b[i][j] == 1 && o > 3) ans[i][j] = 0;
                else if (b[i][j] == 0 && o == 3) ans[i][j] = 1;
            }
        }

        b = ans;
    }
};