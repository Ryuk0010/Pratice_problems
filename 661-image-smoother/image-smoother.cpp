class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int arrX[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
        int arrY[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
        int n = img.size();
        int m = img[0].size();
        vector<vector<int>> ansVec(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int newX;
                int newY;
                int sum = 0;
                int count = 0;
                for(int k = 0; k < 9; k++){
                    newX = i + arrX[k];
                    newY = j + arrY[k];
                    if(newX >= 0 && newX < n && newY >= 0 && newY < m){
                        sum += img[newX][newY];
                        count++;
                    }
                    
                }
                ansVec[i][j] = sum/count;
            }
        }
        return ansVec;
    }
};