class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<string, int> mpp;
        for(auto it: arr1){
            string conStr = to_string(it);
            string str = "";
            for(auto i: conStr){
                str += i;
                mpp[str]++; 
            }
        }
        int ans = 0;
        for(auto it: arr2){
            string conStr = to_string(it);
            string str = "";
            for(auto i: conStr){
                str += i;
                if(mpp.find(str) != mpp.end()){
                    ans = max(ans, static_cast<int>(str.length()));
                }
            }
        }
        return ans;
    }
};