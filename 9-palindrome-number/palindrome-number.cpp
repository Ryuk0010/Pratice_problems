class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int org = x;
        long long num = 0;
        while(x){
            num = (num*10) + x%10;
            x/=10;
        }
        if(num == org) return true;
        return false;
    }
};