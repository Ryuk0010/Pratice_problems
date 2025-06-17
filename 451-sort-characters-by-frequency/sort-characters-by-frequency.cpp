class Solution {
public:
    string frequencySort(string s) {
        string ans = "";
        priority_queue<pair<int, char>> pq;
        unordered_map<char, int> mpp;
        for(auto it: s) mpp[it]++;
        for(auto it: mpp) pq.push({it.second, it.first});

        while(!pq.empty()){
            auto [freq, ch] = pq.top();
            pq.pop();
            ans.append(freq, ch);
        }
        return ans;
    }
};