class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mpp;
        int ans = 0, i = 0;
        int freq = 0;
        for(int j = 0; j < s.size(); j++){
            mpp[s[j]]++;
            freq = max(freq, mpp[s[j]]);
            while((j-i+1) - freq > k){
                mpp[s[i]]--;
                i++;
            }
            ans = max(ans, j-i+1);
        }
        return ans;
    }
};