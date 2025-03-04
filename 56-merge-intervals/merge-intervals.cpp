class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        vector<pair<int, int>> temp;
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        int pFirstEle = intervals[0][0];
        int pSecondEle = intervals[0][1];
        for(int i = 1; i < n; i++){
            int cFirstEle = intervals[i][0];
            int cSecondEle = intervals[i][1];
            if(cFirstEle <= pSecondEle){ 
                pSecondEle = max(pSecondEle, cSecondEle);
            }
            else{
                ans.push_back({pFirstEle, pSecondEle});
                pFirstEle = cFirstEle;
                pSecondEle = cSecondEle;
            }

        }
        ans.push_back({pFirstEle, pSecondEle});
        return ans;
    }
};