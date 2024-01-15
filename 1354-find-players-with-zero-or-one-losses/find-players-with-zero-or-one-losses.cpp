class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
      int n = matches.size();
      unordered_map<int, int> lost;
      vector<vector<int>> ans(2);
      unordered_set<int> st;
      for(int i = 0; i < n; i++){
        int temp = matches[i][1];
        lost[temp]++;
      }
      for(auto it: lost){
        if(it.second == 1){
          ans[1].push_back(it.first);
        }
      }
      for(int i = 0; i < n; i++){
        if(lost.find(matches[i][0]) == lost.end()){
          st.insert(matches[i][0]);
        }
        // lost.erase(matches[i][0]);
      }
      for(auto it: st){
        auto i = it;
        ans[0].push_back(i);
      }
      sort(ans[0].begin(), ans[0].end());
      sort(ans[1].begin(), ans[1].end());
      return ans;
    }
};