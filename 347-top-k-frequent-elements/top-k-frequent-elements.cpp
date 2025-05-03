class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        for (int num : nums) {
            freqMap[num]++;
        }
        int n = nums.size();
        vector<vector<int>> bucket(n + 1);

        for (auto [num, freq] : freqMap) {
            bucket[freq].push_back(num);
        }

        vector<int> ans;
        for (int i = n; i >= 0 && ans.size() < k; --i) {
            for (int num : bucket[i]) {
                ans.push_back(num);
                if (ans.size() == k) break;
            }
        }

        return ans;
    }
};
