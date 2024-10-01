class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> freq(k, 0);
        for(auto it: arr) freq[((it % k) + k) % k]++;

        if(freq[0] % 2) return false;

        for(int i = 1; i <= k/2; i++){
            if(freq[k-i] != freq[i]) return false;
        }
        return true;
    }
};