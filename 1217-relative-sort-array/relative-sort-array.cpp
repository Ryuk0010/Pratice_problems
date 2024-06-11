class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> freq;
        vector<int> ans;
        int m = arr1.size(), n = arr2.size();
        for(int i = 0; i < m; i++){
          freq[arr1[i]]++;
        }
        for(int i = 0; i < n; i++){
          int num = arr2[i];
          while(freq[num]){
            ans.push_back(num);
            freq[num]--;
            if(freq[num] == 0){
              freq.erase(num);
              break;
            } 
          }
        }
        for(auto &it : freq){
          int num = it.first;
          while(freq.size()){
            ans.push_back(num);
            freq[num]--;
            if(freq[num] == 0){
              freq.erase(num);
              break;
            }
          }
        }
        return ans;
    }
};