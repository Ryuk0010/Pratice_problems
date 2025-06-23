class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> mpp1;
        unordered_map<int, int> mpp2;
        vector<int> ans;
        for(auto it: queries){
            int b = it[0];
            int c = it[1];
            if(mpp1.count(b)){
                mpp2[mpp1[b]]--;
                if(mpp2[mpp1[b]] == 0) mpp2.erase(mpp1[b]);
            }
            mpp1[b] = c;
            mpp2[c]++;

            ans.push_back(mpp2.size());
        }
        return ans;
    }
};