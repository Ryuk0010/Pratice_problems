class Solution {
public:
    bool checkDivisibility(int n) {
        int c = n;
        int mul = 1;
        int sum = 0;
        while(n){
            sum += n % 10;
            mul *= n % 10;
            n /= 10;
        }
        int total = sum + mul;
        if(c % total == 0) return true;
        else return false;

    }
};