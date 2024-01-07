class Solution {
private:
    int dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>>& grid, int &count){
      int dx[4] = {0,0,1,-1};
      int dy[4] = {1,-1,0,0};
      count++;
      int n = grid.size();
      int m = grid[0].size();
      vis[row][col] = 1;
      for(int i = 0; i < 4; i++){
        int nr = row + dx[i];
        int nc = col + dy[i];
        if(nr >= 0 && nc >= 00 && nr < n && nc < m && grid[nr][nc] == 1 && vis[nr][nc] == -1){
          vis[nr][nc] = 1;
          dfs(nr, nc, vis, grid, count);
        }
      }
      return 0;
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
      int n = grid.size();
      int m = grid[0].size();
      vector<vector<int>> vis(n, vector<int>(m, -1));
      int count = 0;
        // for(int i = 0; i < n; i++){
        //   if(grid[0][i] == 1) dfs(0, i, vis, grid, count);
        //   if(grid[n-1][i] == 1) dfs(n-1, i, vis, grid, count);
        // }
        // for(int j = 1; j < m-1; j++){
        //   if(grid[j][0] == 1) dfs(j, 0, vis, grid, count);
        //   if(grid[j][m-1] == 1) dfs(j, m-1, vis, grid, count);
        // }
        for( int i = 0; i<n; i++ ){
                    for( int j = 0 ; j<m; j++ ){
                        if( i == 0 || i == n - 1 || j == 0 || j == m - 1 ){
                            if( grid[i][j] == 1 && vis[i][j] == -1){
                                dfs(i,j,vis,grid,count);
                            }
                        }
                    }
                }

        int land = 0;
        for(int i = 0; i < n; i++){
          for(int j = 0; j < m; j++){
            if(grid[i][j] == 1) land++;
          }
        }
        cout << count;
        return land-count;
    }
};