class Solution {
public:
vector<int> arr;
    Solution(vector<int>& w) {
        for(auto it: w){
            if(arr.empty()) arr.push_back(it);
            else arr.push_back(arr.back() + it);
        }
    }
    
    int pickIndex() {
        int x = rand() % arr.back();
        auto itr = upper_bound(arr.begin(), arr.end(), x);
        return itr - arr.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */