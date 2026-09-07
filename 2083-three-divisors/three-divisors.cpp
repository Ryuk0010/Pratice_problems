class Solution {
public:
    bool isThree(int n) {
        int sqrtn = sqrt(n);
        if(sqrtn *sqrtn != n) {
            return false;
        }
        if(sqrtn < 2) {
            return false;
        }
        for(int i = 2; i <= sqrt(sqrtn); i++) {
            if(sqrtn % i == 0) {
                return false;
            }
        }
        return true;
    }
};


