class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        
        if (m > n) return false;

        vector<int> s1_freq(26, 0), window_freq(26, 0);

        for (char c : s1) {
            s1_freq[c - 'a']++;
        }

        for (int i = 0; i < m; i++) {
            window_freq[s2[i] - 'a']++;
        }

        for (int i = 0; i <= n - m; i++) {
            if (s1_freq == window_freq) {
                return true;
            }

            if (i + m < n) {
                window_freq[s2[i] - 'a']--;
                window_freq[s2[i + m] - 'a']++;
            }
        }

        return false;
    }
};