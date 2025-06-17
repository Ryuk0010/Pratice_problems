class Solution {
public:
    int solve(int n, int r){
        long long ans = 1;
        for(int i = 1; i <= r; i++){
            ans = (ans * (n-i+1)) / i;
        }
        return (int)ans;
    }
    int uniquePaths(int m, int n) {
        return solve(m+n-2, min(m-1, n-1));
    }
};