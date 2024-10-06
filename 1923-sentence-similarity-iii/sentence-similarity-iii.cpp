class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        vector<string> a, b;
        string c1, c2;
        stringstream iss1(s1), iss2(s2);
        
        // Split both strings into words
        while (iss1 >> c1) {
            a.push_back(c1);
        }
        while (iss2 >> c2) {
            b.push_back(c2);
        }
        
        // Use two pointers to compare from the front and back
        int i = 0, j = 0;
        int n1 = a.size(), n2 = b.size();
        
        // Compare from the front
        while (i < n1 && i < n2 && a[i] == b[i]) {
            ++i;
        }
        
        // Compare from the back
        while (j < n1 - i && j < n2 - i && a[n1 - 1 - j] == b[n2 - 1 - j]) {
            ++j;
        }
        
        // If the entire strings can be matched by skipping the middle part, return true
        return i + j == n1 || i + j == n2;
    }
};