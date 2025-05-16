class Solution {
public:
    bool hammingDist(string s1, string s2){
        int check = 0;
        for(int i = 0; i < s1.size(); i++){
            if(s1[i] != s2[i]) check++;
        }
        if(check > 1) return false;
        return true;
    }
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        int index = 0;  
        int longSubStr = 1;
        vector<int> prevInd(n, -1);
        vector<int> dp(n, 1);
        for(int i = 0; i < n; i++){
            for(int j = 0; j <= i-1; j++){
                if(groups[i] != groups[j] && words[i].length() == words[j].length() && hammingDist(words[i], words[j])){
                    if(dp[i] < dp[j]+1){
                        dp[i] = dp[j]+1;
                        prevInd[i] = j;
                        if(longSubStr < dp[i]){
                            longSubStr = dp[i];
                            index = i;
                        }
                    }
                    
                }   
            }
        }
        vector<string> res;
        while(index != -1){
            res.push_back(words[index]);
            index = prevInd[index];
        }
        reverse(res.begin(), res.end());
        return res;
    }
};