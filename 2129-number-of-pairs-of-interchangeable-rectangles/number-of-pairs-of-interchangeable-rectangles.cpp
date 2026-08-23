class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        map<pair<int, int>, int> mpp;
        long long ans = 0;
        int n = rectangles.size();
        for(int i = 0; i < n; i++){
            int g = gcd(rectangles[i][0], rectangles[i][1]);
            int a = rectangles[i][0] / g;
            int b = rectangles[i][1] / g;
            mpp[{a, b}]++;
        }
        for(auto it: mpp){
            if(it.second > 1){
                ans += ((long long)it.second*(long long)(it.second-1)) / 2;
            }
        }
        return ans;
    }
};