class Solution {
public:
    double myPow(double x, int n) {
        long long m = n;
        double ans = 1.0000;
        if(n < 0) m = -m;
        while(m){
            if(m%2){
                ans *= x;
                m -= 1;
            }
            else{
                x *= x;
                m /= 2; 
            }
        }
        if(n < 0) ans = 1/ans;
        return ans;
    }
};