class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
    int n = board.size();
    vector<int> nb(n * n);
    int index = 0;
    bool t = true;
    for (int i = n - 1; i >= 0; i--) {
        if (t) {
            for (int j = 0; j < n; j++) {
                nb[index++] = board[i][j];
            }
        } else {
            for (int j = n - 1; j >= 0; j--) {
                nb[index++] = board[i][j];
            }
        }
        t = !t;
    }
    vector<int> dist(n * n, -1);
    queue<int> q;
    q.push(0);
    dist[0] = 0;
     while (!q.empty()) {
        int curr = q.front();
        q.pop();
        if (curr == n * n - 1) {
            return dist[curr];
        }
        for (int i = 1; i <= 6; i++) {
            int next = curr + i;
            if (next >= n * n) {
                continue;
            }
            if (nb[next] != -1) {
                next = nb[next] - 1;
            }
            if (dist[next] == -1) {
                dist[next] = dist[curr] + 1;
                q.push(next);
            }
        }
    }
    return -1;

    }
};