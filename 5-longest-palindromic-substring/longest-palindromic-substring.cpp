class Solution {
public:
    bool solve(int i, int j, string& s){
        while(i <= j){
            if(s[i] != s[j]) return false; 
            i++;
            j--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int n = s.length();
        int len = INT_MIN;
        int k = 0;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(solve(i, j, s)){
                    if(j-i+1 > len){
                        len = j-i+1;
                        k = i;
                    }
                }
            }
        }
        return s.substr(k, len);
    }
};