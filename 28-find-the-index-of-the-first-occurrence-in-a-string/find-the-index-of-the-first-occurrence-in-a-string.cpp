class Solution {
public:
    int strStr(string haystack, string needle) {
      int x = needle.size(); 
        for(int i = 0; i < haystack.size(); i++){
            if(needle == haystack.substr(i, x)) return i;

        }  
      return -1;
    }
};