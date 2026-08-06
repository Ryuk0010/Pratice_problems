class Solution {
public:
    int ck(int n){
        int ans = 1;
        while(n){
            ans *= n%10;
            n /= 10;
        }
        return ans;
    }
    int smallestNumber(int n, int t) {
        while(ck(n) % t != 0) n++;
        return n;
    }
};