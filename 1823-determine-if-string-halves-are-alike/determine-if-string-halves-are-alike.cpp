class Solution {
public:
    bool halvesAreAlike(string s) {
      unordered_set<char> st{'a','e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
      int mid = s.size() / 2;
      int count = 0;
      for(int i = 0; i < mid; i++){
        char a = s[i];
        char b = s[mid + i];
        
        if(st.count(a)) count++;
        if(st.count(b)) count--;
      }
        if(count == 0) return true;
        else return false;
    }
};