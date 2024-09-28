class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        int n = word1.size(), i, j;
        vector<int> base(26);
        for(auto it: word2) base[it - 'a']++;

        vector<vector<int>> pre(n+1, vector<int> (26, 0));
        for(i = 0; i < n; i++){
            pre[i + 1][word1[i] - 'a']++;
            for(j = 0; j < 26; j++){
                pre[i + 1][j] += pre[i][j];
            }
        }
        long long ans = 0;
        for(i = 0; i < n; i++){
            int l = i, r = n - 1, idx = 1e9;
            while(l <= r){
                int mid = (l + r) / 2;
                bool ok = true;
                for(j = 0; j < 26; j++){
                    if(base[j] > pre[mid+1][j] - pre[i][j]){
                        ok = false;
                        break;
                    }
                }
                if(ok){
                    idx = mid;
                    r = mid - 1;
                }
                else{
                    l = mid + 1;
                }
            }
            if(idx < 1e9) ans += (n-idx);
        }
        return ans;
    }
};