class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> minDist(n, INT_MAX); // minimum distance to each point
        vector<bool> inMST(n, false); // points already included in MST
        minDist[0] = 0; // start from the first point
        int sum = 0;

        for (int i = 0; i < n; ++i) {
            int u = -1;

            // Find the point with the minimum distance to the MST
            for (int j = 0; j < n; ++j) {
                if (!inMST[j] && (u == -1 || minDist[j] < minDist[u])) {
                    u = j;
                }
            }

            sum += minDist[u];
            inMST[u] = true;

            // Update the minimum distances to the MST
            for (int v = 0; v < n; ++v) {
                if (!inMST[v]) {
                    int weight = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                    if (weight < minDist[v]) {
                        minDist[v] = weight;
                    }
                }
            }
        }

        return sum;
    }
};
