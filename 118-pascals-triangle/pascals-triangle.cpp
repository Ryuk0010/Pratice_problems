class Solution {
public:
    int solve(int n, int r) {
        int result = 1;
        for (int i = 0; i < r; i++) {
            result = result * (n - i) / (i + 1);
        }
        return result;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascalTriangle(numRows);

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j <= i; j++) {
                pascalTriangle[i].push_back(solve(i, j));
            }
        }
        return pascalTriangle;
    }
};