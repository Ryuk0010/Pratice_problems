class Solution {
public:
    int ncr(int n, int r){
        long long int ans = 1;
        for(int i = 1; i <= r; i++){
            ans = (ans*(n-i+1))/i; 
        }
        return (int)ans;
    }
    int uniquePaths(int m, int n) {
        return ncr(m+n-2, min(m-1, n-1));
    }
};