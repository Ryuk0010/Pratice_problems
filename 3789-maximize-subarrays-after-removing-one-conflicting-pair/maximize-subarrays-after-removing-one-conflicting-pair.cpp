class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        vector<vector<int>> pairs(n+1);
        long long valid = 0;
        vector<long long> extra(n+1, 0);
        for(auto& it: conflictingPairs){
            int a = it[0], b = it[1];
            if(a < b) swap(a, b);
            pairs[a].push_back(b);
        }
        int gtr = 0;
        int secGtr = 0;
        for(int i = 1; i <= n; i++){
            auto& arr = pairs[i];
            for(int j = 0; j < arr.size(); j++){
                if(arr[j] > gtr){
                    secGtr = gtr;
                    gtr = arr[j];
                }
                else if(arr[j] > secGtr){
                    secGtr = arr[j];
                }
            }
            
            valid += i - gtr;
            extra[gtr] += gtr - secGtr;

        }
        return valid + *max_element(extra.begin(), extra.end());
    }
};