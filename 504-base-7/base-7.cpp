class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0) return "0";
        int temp = num;
        string ans = "";
        if(num < 0) temp = -num;
        while(temp){
            ans = to_string(temp%7) + ans;
            temp /= 7;
        }
        if(num < 0) return "-"+ans;
        return ans;

    }
};