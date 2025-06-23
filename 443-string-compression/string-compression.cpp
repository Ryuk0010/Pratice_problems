class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;
        int j = 0;
        while(i < chars.size()){
            char curchar = chars[i];
            int cnt = 0;
            while(i < chars.size() && chars[i] == curchar){
                i++;
                cnt++;
            }
            chars[j] = curchar;
            j++;
            if(cnt > 1){
                for(char c : to_string(cnt)){
                    chars[j] = c;
                    j++;
                }
            }
        }
        return j;
    }
};