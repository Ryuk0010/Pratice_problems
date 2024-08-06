class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);
        for (char c : word) {
            freq[c - 'a']++;
        }
        
        sort(freq.rbegin(), freq.rend());
        
        int totalPress = 0;
        int press = 1;
        for (int i = 0; i < 26; i++) {
            totalPress += freq[i]*(i / 8 + 1);
        }
        
        return totalPress;
    }
};