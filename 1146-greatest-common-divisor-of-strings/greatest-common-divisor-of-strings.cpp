class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1 + str2 != str2 + str1) return "";

        auto gcd = [](int l1, int l2){
            while(l2){
                int temp = l1 % l2;
                l1 = l2;
                l2 = temp;
            }
            return l1;
        };

        int ans = gcd(str1.length(), str2.length());
        return str1.substr(0, ans);
    }
};