class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int oldc = image[sr][sc];
        vector<vector<int>> visit(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        vector<vector<int>> ans;
        ans = image;
        q.push({sr, sc});
        // visit[sr][sc] = 1;
        ans[sr][sc] = color;
        int drow[] = {-1, 1, 0, 0};
        int dcol[] = {0, 0, -1, 1};
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m){
                    if(image[nrow][ncol] == oldc && visit[nrow][ncol] != 1){
                        visit[nrow][ncol] = 1;
                        ans[nrow][ncol] = color;
                        q.push({nrow, ncol});
                    }
                }
            }
        }
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < m; j++){
        //         cout << ans[i][j];
        //     }

        //     cout << endl;
        // }
        return ans;
    }
};