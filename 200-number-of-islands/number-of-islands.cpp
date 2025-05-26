class Solution {
public:
    void dfs(vector<vector<char>>& grid, int row, int col) {
        if (grid[row][col] != '1') return;
        grid[row][col] = '0';

        if (row > 0 && grid[row - 1][col] == '1') dfs(grid, row - 1, col);
        if (row < grid.size() - 1 && grid[row + 1][col] == '1') dfs(grid, row + 1, col);
        if (col > 0 && grid[row][col - 1] == '1') dfs(grid, row, col - 1);
        if (col < grid[0].size() - 1 && grid[row][col + 1] == '1') dfs(grid, row, col + 1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') {
                    cnt++;
                    dfs(grid, i, j);
                }
            }
        }

        return cnt;
    }
};