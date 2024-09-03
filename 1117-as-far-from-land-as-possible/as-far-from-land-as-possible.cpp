class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        
        
        bool allWater = true, allLand = true;
        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                if (grid[r][c] == 1) allWater = false;
                if (grid[r][c] == 0) allLand = false;
            }
        }
        if (allWater || allLand) return -1;

        
        queue<tuple<int, int, int>> q;
        set<pair<int, int>> visited;
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int res = 0;
        
        
        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                if (grid[r][c] == 1) {
                    q.push({r, c, 0});
                    visited.insert({r, c});
                }
            }
        }

       
        while (!q.empty()) {
            auto [r, c, dist] = q.front();
            q.pop();
            for (auto [i, j] : directions) {
                int next_row = r + i;
                int next_col = c + j;
                if (next_row >= 0 && next_row < ROWS && next_col >= 0 && next_col < COLS && visited.find({next_row, next_col}) == visited.end()) {
                    int new_dist = dist + 1;
                    res = max(res, new_dist);
                    q.push({next_row, next_col, new_dist});
                    visited.insert({next_row, next_col});
                }
            }
        }
        return res;
    }
};