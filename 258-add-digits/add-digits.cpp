class Solution {
public:
    int callfn(int num){
        int a = 0;
        while(num){
            a += num%10;
            num /= 10; 
        }
        return a;
    }
    int addDigits(int num) {

        while(to_string(num).length() > 1){
            num = callfn(num);
        }
        return num;
    }
};