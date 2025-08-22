class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last(26, 0);
        
        for (int i = 0; i < s.size(); i++) {
            last[s[i] - 'a'] = i;
        }

        vector<int> result;
        int maxLast = 0, prevEnd = -1;

        for (int i = 0; i < s.size(); i++) {
            maxLast = max(maxLast, last[s[i] - 'a']);

            if (i == maxLast) {
                result.push_back(i - prevEnd);
                prevEnd = i;
            }
        }

        return result;
    }
};