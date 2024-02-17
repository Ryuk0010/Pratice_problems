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
            mat[j][sc] += 1;
            if(ec < n-1) mat[j][ec+1] -= 1;
          }
        }
        for(int i = 0; i < n; i++){
          for(int j = 1; j < n; j++){
            mat[i][j] += mat[i][j-1];
          }
        }
      return mat;
    }
};