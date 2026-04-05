class Solution {
public:
    int mirrorFrequency(string s) {
        vector<int> ch(26, 0);
        vector<int> dig(10, 0);
        int ans = 0;
        for(auto it: s) (it >= 'a' && it <= 'z') ? ch[it-'a']++ : dig[it-'0']++;
        for(int i = 0; i < 26; i++){
            ans += abs(ch[i] - ch[25-i]);
            ch[25-i] = 0;
            ch[i] = 0;
        }
        for(int i = 0; i < 10; i++){
            ans += abs(dig[i] - dig[9-i]);
            dig[9-i] = 0;
            dig[i] = 0;
        }
        return ans;
    }
};