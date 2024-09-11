class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int ref = 2, maxArea = -1;
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int k = find_val(ref, grid, i, j);
                    mp[ref] = k;
                    ref += 1;
                    maxArea = max(maxArea, k);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    int sum = 0;
                    unordered_set<int> seen;
                    if (i > 0) seen.insert(grid[i-1][j]);
                    if (j > 0) seen.insert(grid[i][j-1]);
                    if (i < n-1) seen.insert(grid[i+1][j]);
                    if (j < n-1) seen.insert(grid[i][j+1]);
                    for (int val : seen) {
                        sum += mp[val];
                    }
                    maxArea = max(maxArea, sum + 1);
                }
            }
        }
        return maxArea;
    }

    int find_val(int ref, vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0 || grid[i][j] == ref) {
            return 0;
        }
        grid[i][j] = ref;
        return 1 + find_val(ref, grid, i+1, j) + find_val(ref, grid, i-1, j) + find_val(ref, grid, i, j+1) + find_val(ref, grid, i, j-1);
    }
};