class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int l = 0;
        int ans = 0;
        unordered_map<int, int> mpp;
        for(auto it: s){
            mpp[it]++;
            while(mpp[it] == k){
                mpp[s[l]]--;
                l++;
            }
            ans += l;
        }
        return ans;
    }
};