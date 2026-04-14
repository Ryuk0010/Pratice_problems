class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix[0].size();
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j]) cnt++;
            }
            ans.push_back(cnt);
            cnt = 0;
        }
        return ans;
    }
};