class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() <= 1) return intervals;
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int prev1 = intervals[0][0];
        int prev2 = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++){
            int cur1 = intervals[i][0];
            int cur2 = intervals[i][1];

            if(cur1 <= prev2){
                prev2 = max(prev2, cur2);
            }
            else{
                ans.push_back({prev1, prev2});
                prev1 = cur1;
                prev2 = cur2;
            }
        }
        ans.push_back({prev1, prev2});
        return ans;
    }
};