class Solution {
public:
    bool isValid(int i, int j, int n, int m, vector<string> &matrix) {
        if(i < 0 || j < 0 || i >= n || j >= m) return false;
        if(matrix[i][j] == '#') return false;
        return true;
    }
    
    int minMoves(vector<string> &matrix) {
        int n = matrix.size(), m = matrix[0].size();

        unordered_map<char, vector<pair<int, int>>> cells;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] != '.' && matrix[i][j] != '#') {
                    cells[matrix[i][j]].push_back({i, j});
                }
            }
        }

        if(matrix[n - 1][m - 1] == '#') return -1;

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        vector<vector<int>> dist(n, vector<int> (m, INT_MAX));
        unordered_set<char> used;
        
        pq.push({0, 0, 0});
        dist[0][0] = 0;

        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {-1, 1, 0, 0};

        while(!pq.empty()) {
            auto [curDist, x, y] = pq.top();
            pq.pop();
            
            if(curDist > dist[x][y]) continue;
            if(x == n - 1 && y == m - 1) return curDist;

            if(isupper(matrix[x][y]) && used.find(matrix[x][y]) == used.end()) {
                used.insert(matrix[x][y]);

                for(auto &[newX, newY]: cells[matrix[x][y]]) {
                    if(curDist < dist[newX][newY]) {
                        dist[newX][newY] = curDist;
                        pq.push({curDist, newX, newY});
                    }
                }
            }
            
            for(int k = 0; k < 4; k++) {
                int nextX = x + dx[k], nextY = y + dy[k];
                
                if(isValid(nextX, nextY, n, m, matrix) && curDist + 1 < dist[nextX][nextY]) {
                    dist[nextX][nextY] = curDist + 1;
                    pq.push({curDist + 1, nextX, nextY});
                }
            }
        }

        return -1;
    }
};