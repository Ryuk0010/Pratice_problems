class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int i = x;
        int j = x + k - 1;
        while(i <= j){
            for(int a = y; a < k + y; a++){
                swap(grid[i][a], grid[j][a]);
            }
            i++, j--;
        }
        return grid;
    }
};