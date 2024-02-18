class Solution 
{
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries){
      set<char> vowels = {'a','e','i','o','u'};
      vector<int> prefix_sum, res;
      int cnt = 0;
        for(auto &it : words){
          if(vowels.count(it[0])==1 && vowels.count(it[it.size()-1])) cnt++;   
          prefix_sum.push_back(cnt);
        }
        for(auto &it:queries){
          if(it[0] > 0) cnt = prefix_sum[it[1]] - prefix_sum[it[0]-1];
          else cnt = prefix_sum[it[1]];
          res.push_back(cnt);    
        }
      return res;  
    }
};