class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        int sr, sc, er, ec;
        vector<vector<int>> mat(n, vector<int>(n, 0));
        for(int i = 0; i < queries.size(); i++){
            sr = queries[i][0];
            sc = queries[i][1];
            er = queries[i][2];
            ec = queries[i][3];
            for(int j = sr; j <= er; j++){
                for(int k = sc; k <= ec; k++){
                    mat[j][k] = mat[j][k] + 1;
                }
            }
        }
        return mat;
    }
};