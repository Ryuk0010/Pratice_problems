class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt = 0;
        int extra = 0;
        for(auto it: s){
            if(it == '(') cnt++;
            else{
                cnt > 0 ? cnt-- : extra++;
            }
        }
        return cnt + extra;
    }
};