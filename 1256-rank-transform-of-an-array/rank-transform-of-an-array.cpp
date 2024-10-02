class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, int> mpp;
        vector<int> copy(arr.begin(), arr.end());
        sort(copy.begin(), copy.end());
        int ind = 0;
        for(int i = 0; i < copy.size(); i++){
            if(!mpp.count(copy[i]))mpp[copy[i]] = ++ind;
        }
        for(int i = 0; i < arr.size(); i++){
            copy[i] = mpp.find(arr[i])->second;
        }
        return copy;
    }
};