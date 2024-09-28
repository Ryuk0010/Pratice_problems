class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        vector<int> req(26, 0), cnt(26, 0);
        int n = word1.size();

        for(int i = 0; i < word2.size(); i++) req[word2[i] - 'a']++;

        auto check = [&] () {
            for(int i = 0 ; i < 26; i++){
                if(req[i] > cnt[i]) return false;
            }
            return true;
        };

        cnt[word1[0] - 'a']++;
        long long ans = 0;
        for(int l = 0, r = 0; l < n; l++){
            while(r < n && !check()){
                r++;
                if(r < n) cnt[word1[r] - 'a']++;
            }
            ans += n - r;
            cnt[word1[l] - 'a']--;
        }
        return ans;
    }
};