class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        int ans = 0;
        auto cmp = [](vector<int>&a, vector<int>&b){
            if(a[0] == b[0]) return b[1] < a[1];
            return a[0] < b[0];
        };
        sort(envelopes.begin(), envelopes.end(), cmp);
        for(int i = 0; i < n; i++){
            cout << envelopes[i][0] <<" "<< envelopes[i][1] << endl;
        }
        vector<int> lis;
        for(int i = 0; i < n; i++){
            int ele = envelopes[i][1];
            int idx = lower_bound(lis.begin(), lis.end(), ele) - lis.begin();
            if(idx >= lis.size()) lis.push_back(ele);
            else lis[idx] = ele;
        }
        return lis.size();
    }
};