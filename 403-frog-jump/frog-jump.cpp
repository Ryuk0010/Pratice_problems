class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, unordered_set<int>> mpp;

        mpp[stones[0] + 1] = {1};
        for(int i = 1; i < stones.size(); i++){
            int s = stones[i];

            for(auto it: mpp[s]){
                mpp[s + it].insert(it);
                mpp[s + it + 1].insert(it+1);
                mpp[s + it - 1].insert(it-1);
            }
        }
        return mpp[stones.back()].size() >= 1 ? true: false;
    }
};