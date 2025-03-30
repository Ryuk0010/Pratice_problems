class Solution {
public:
    int nextGreaterElement(int n) {
        string str = to_string(n);
        int i = str.length()-1;
        while(i > 0 && str[i] <= str[i-1]) i--;

        if(i == 0) return -1;
        
        int j = str.length() - 1;
        while(i <= j && str[i-1] >= str[j]) j--;

        swap(str[i-1], str[j]);
        reverse(str.begin()+i, str.end());
        
        long long result = stoll(str);
        if(result > INT_MAX){
            return -1;
        }
        return (int)result;
    }
};