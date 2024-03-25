class Solution {
public:
    int numTrees(int n) {
        vector<int>result (n+1, 0); 
        result[1] = result[0] = 1;
        for(int i=2; i<=n; i++){
            for(int j=1; j<=i; j++){
                result[i] += result[j-1]*result[i-j];
            }
        }
         for(int j=0;j<=n;j++){
          cout << result[j] <<" ";
         }
        return result[n]; 
    }
};