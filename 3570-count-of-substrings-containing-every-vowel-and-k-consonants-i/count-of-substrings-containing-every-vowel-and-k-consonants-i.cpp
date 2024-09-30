class Solution {
public:
    bool isVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
    int countOfSubstrings(string word, int k) {
        int s = 0, e = 0, cnstCnt = 0;
        int n = word.length();
        int ans = 0;
        unordered_map<char, int> freq;


        vector<int> lastCnst(n, 0);
        int lastC = n;
        for(int i = n-1; i >= 0; i--){
            lastCnst[i] = lastC;
            if(!isVowel(word[i])){
                lastC = i;
            }
        }


        while(e < n){
            if(isVowel(word[e])){
                freq[word[e]]++;
            }
            else cnstCnt++;

            while(s <= e && cnstCnt > k){
                if(isVowel(word[s])){
                    if(--freq[word[s]] == 0) freq.erase(word[s]);
                }
                else cnstCnt--;
                s++;
            }
            while(s <= e && freq.size() == 5 && cnstCnt == k){
                ans += lastCnst[e] - e;
                if(isVowel(word[s])){
                    if(--freq[word[s]] == 0) freq.erase(word[s]);
                }
                else cnstCnt--;
                s++;
            }
            e++;
        }
        return ans;
    }
};