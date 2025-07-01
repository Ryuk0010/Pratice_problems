class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int sum1 = 0, sum2 = 0, ans = 0;
        for (int i = 0; i < arr.size(); i++) {
            sum1 += arr[i];
            sum2 += i;
            if (sum1 == sum2){
                ans++;
                sum1 = 0;
                sum2 = 0;
            }
        }
        return ans;
    }
};