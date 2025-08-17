class Solution {
public:
    int minSensors(int n, int m, int k) {
        int dist = 2*k + 1;
        return ceil((double)n/dist) * ceil((double)m/dist);
    }
};