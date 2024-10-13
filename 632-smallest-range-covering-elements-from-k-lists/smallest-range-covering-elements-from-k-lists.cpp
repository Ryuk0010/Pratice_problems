class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, 
        greater<pair<int, pair<int, int>>>> pq;

        int maxi = INT_MIN, mini = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            pq.push({nums[i][0], {i, 0}});
            mini = min(mini, nums[i][0]);
            maxi = max(maxi, nums[i][0]);
        }
        int start = mini, end = maxi;
        while(!pq.empty()){
            pair<int, pair<int, int>> top = pq.top();
            pq.pop();
            mini = top.first;
            if(maxi - mini < end - start){
                start = mini;
                end = maxi;
            }
            int row = top.second.first;
            int col = top.second.second;
            if(col + 1 < nums[row].size()){
                pq.push({nums[row][col + 1], {row, col + 1}});
                maxi = max(maxi, nums[row][col + 1]);
            }
            else break;
        }
        return {start, end};
    }
};