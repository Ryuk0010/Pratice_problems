class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        int t(0), d(n-1), l(0), r(n-1);
        int c = 0;
        int a = 1;
        while(t <= d && l <= r){
            if(c == 0){
                for(int j = l; j <= r; j++){
                    res[t][j] = a++;
                }
                t++;
            }
            if(c == 1){
                for(int j = t; j <= d; j++){
                    res[j][r] = a++;
                }
                r--;
            }
            if(c == 2){
                for(int j = r; j >= l; j--){
                    res[d][j] = a++;
                }
                d--;
            }
            if(c == 3){
                for(int j = d; j >= t; j--){
                    res[j][l] = a++;
                }
                l++;
            }
            c = (c+1)%4;
        }
        return res;
    }
};