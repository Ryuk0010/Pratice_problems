class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(); 
        int m = heights[0].size(); 
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        queue<pair<int, pair<int, int>>> pq;
        pq.push({0, {0, 0}});
        dist[0][0] = 0;
        int x[] = {1, -1, 0, 0};
        int y[] = {0, 0, -1, 1};
        int ans = INT_MAX;
        while(!pq.empty()){
            int preveff = pq.front().first;
            int row = pq.front().second.first;
            int col = pq.front().second.second;
            pq.pop();
            // if(row == n-1 && col == m-1) return preveff;
            for(int i = 0; i < 4; i++){
                int nrow = row + x[i];
                int ncol = col + y[i];
                if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m){
                    int eff = max(abs(heights[nrow][ncol] - heights[row][col]), preveff);
                    if(eff < dist[nrow][ncol]){
                        pq.push({eff,{nrow, ncol}});
                        dist[nrow][ncol] = eff;
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};