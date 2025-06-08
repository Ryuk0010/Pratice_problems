class Solution {
public:
    int firstUniqChar(string s) {
        int frequency[128] = {0}; 

        for(char ch : s){
            frequency[ch]++; 
        }
        for(int i = 0 ; i < s.size();i++){
            if(frequency[s[i]] == 1) 
            return i;
        }
        return -1;
    }
};