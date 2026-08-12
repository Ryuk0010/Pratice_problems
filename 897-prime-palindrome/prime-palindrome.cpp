class Solution {
public:
    bool isPrime(int n){
        for(int i = 2; i*i <= n; i++){
            if(n%i == 0) return false;
        }
        return true;
    }
    int makePal(int n){
        string s = to_string(n);
        string s1 = s;
        reverse(s1.begin(), s1.end());
        int ans = stoi(s + s1.substr(1, s1.length()));
        return ans;
    }
    int primePalindrome(int n) {
        int ans;
        if (n <= 2)
            return 2;
        else if (n <= 3)
            return 3;
        else if (n <= 5)
            return 5;
        else if (n <= 7)
            return 7;
        else if (n <= 11)
            return 11;
        for(int i = 1; ; i++){
            int pal = makePal(i);
            if(pal >= n && isPrime(pal)){
                ans = pal;
                break;
            } 
        }
        return ans;
    }
};