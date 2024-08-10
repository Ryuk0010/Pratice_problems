class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, unordered_set<int>> mp;

        mp[stones[0] + 1] = {1};
        for(int i = 1; i < stones.size(); ++i){
            int stone = stones[i];

            for(auto it : mp[stone]){
                mp[stone + it].insert(it);
                mp[stone + it + 1].insert(it + 1);
                mp[stone + it - 1].insert(it - 1);
            }
        }
        return mp[stones.back()].size();
    }
};