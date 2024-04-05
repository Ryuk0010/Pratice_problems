class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string str = strs[0];
        for(int i = 1; i < strs.size(); i++){
            while(strs[i].find(str)){
                str = str.substr(0, str.length()-1);
                if(str.empty()) return "";
            }
        }
        return str;
    }
};