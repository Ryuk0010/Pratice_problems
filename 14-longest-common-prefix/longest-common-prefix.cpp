class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string ans = "";
        string str1 = strs[0];
        string str2 = strs[strs.size()-1];
        for(int i = 0; i < min(str1.length(), str2.length()); i++){
            if(str1[i] != str2[i]) break;
            ans+= str1[i];
        }
        return ans;
    }
};