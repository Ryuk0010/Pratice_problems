class Solution {
public:
    int numberOfSubstrings(string s) {
        int output = 0;
    int n = s.length();
    std::vector<int> prefix(n, 0);

    // Calculate prefix sums
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            prefix[i] = (s[i] == '1') ? 1 : 0;
        } else {
            prefix[i] = prefix[i - 1] + ((s[i] == '1') ? 1 : 0);
        }
    }

    // Iterate through substrings
    for (int i = 0; i < n; ++i) {
        int count = 0, one = 0;
        for (int j = i; j < n; ++j) {
            one = prefix[j] - ((i == 0) ? 0 : prefix[i - 1]); // count of one
            count = j - i + 1 - one;  // count of zero
            if (count * count > one) {
                j += (count * count - one - 1);  // jump where next solution is possible
            }
            if (count * count <= one) {
                int kl = static_cast<int>(std::sqrt(one));
                output++;
                if (kl > count) {  // again jump where zero can be greater than one.
                    output += (j + (kl - count)) >= n ? (n - j - 1) : (kl - count); // ensure not to exceed the length
                    j = j + (kl - count);
                }
            }
        }
    }

    return output;
    }
};