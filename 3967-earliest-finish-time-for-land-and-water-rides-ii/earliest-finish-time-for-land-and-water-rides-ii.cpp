class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int ans = INT_MAX;

        int n = landStartTime.size();
        int minEnd = INT_MAX;
        for (int i = 0; i < n; i++) {
            minEnd = min(minEnd, landStartTime[i] + landDuration[i]);
        }
        int m = waterStartTime.size();

        for (int i = 0; i < m; i++) {
            ans = min(ans, waterDuration[i] + max(minEnd, waterStartTime[i]));
        }

        minEnd = INT_MAX;
        for (int i = 0; i < m; i++) {
            minEnd = min(minEnd, waterStartTime[i] + waterDuration[i]);
        }

        for (int i = 0; i < n; i++) {
            ans = min(ans, landDuration[i] + max(minEnd, landStartTime[i]));
        }

        return ans;

    }
};