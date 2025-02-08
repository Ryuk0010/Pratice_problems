class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> vis(n, vector<int>(n, 0));

        vector<int> x = {1, 1, 1, -1, -1, -1, 0, 0};
        vector<int> y = {1, 0, -1, 1, 0, -1, -1, 1};

        if(grid[0][0] == 1) return -1;
        q.push({1, {0, 0}});
        vis[0][0] = 1;
        while(!q.empty()){
            int wt = q.front().first;;
            int xaxix = q.front().second.first;
            int yaxix = q.front().second.second;
            q.pop();
            if(xaxix == grid.size() - 1 && yaxix == grid.size() - 1) return wt;
            for(int i = 0; i < x.size(); i++){
                int tx = xaxix + x[i];
                int ty = yaxix + y[i];
                if(tx >= 0 && tx < grid.size() && ty >= 0 && ty < grid.size() && vis[tx][ty] == 0 && grid[tx][ty] == 0){
                    q.push({wt+1, {tx, ty}});
                    vis[tx][ty]=1;
                }
            }
        }
        return -1;
    }
};