class NumMatrix {
private:
    int row,col;
    vector<vector<int>> prefix;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        row = matrix.size(), col = matrix[0].size();
        prefix = vector<vector<int>>(row+1, vector<int>(col+1, 0));
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                prefix[i+1][j+1]=matrix[i][j]+prefix[i][j+1]+prefix[i+1][j]-prefix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return prefix[row2+1][col2+1]-prefix[row2+1][col1]-prefix[row1][col2+1]+prefix[row1][col1];
    }
};