class Solution {
public:        
long long MOD = 1e9 + 7;
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, long long> mp;
        long long sum = 0;
        long long ans = 0;


        for (int i = 0; i < points.size(); i++) {
            mp[points[i][1]]++;
        }
        for (auto& it : mp) {
            long long count = it.second;
            long long pairs = (count * (count - 1)) / 2;
            sum += pairs;
        }

        for (auto& it : mp) {
            long long count = it.second;
            long long pairs = (count * (count - 1)) / 2;
            sum -= pairs;
            ans += pairs * sum;
        }

        return ans % MOD;
    }
};