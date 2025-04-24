class Solution {
public:
    int solve(int n, int k){
        if(n == 0) return 0;
        int idx = solve(n-1, k);
        idx+=k;
        return idx % n;
    }
    int findTheWinner(int n, int k) {
        return solve(n, k)+1;
    }
};