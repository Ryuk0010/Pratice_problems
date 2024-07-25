class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    res++;
                    markIsland(grid, i, j);
                }
            }
        }
        return res;
    }
    void markIsland(vector<vector<char>>& grid, int r, int c) {
        if (grid[r][c] != '1') return;
        grid[r][c] = '0';
        if (r > 0 && grid[r - 1][c] == '1') markIsland(grid, r - 1, c);
        if (r < grid.size() - 1 && grid[r + 1][c] == '1') markIsland(grid, r + 1, c);
        if (c > 0 && grid[r][c - 1] == '1') markIsland(grid, r, c - 1);
        if (c < grid[0].size() - 1 && grid[r][c + 1] == '1') markIsland(grid, r, c + 1);
    }
};