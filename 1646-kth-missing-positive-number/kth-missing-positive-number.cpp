class Solution {
public:
    bool isAns(vector<int>& nums, int k, int ans){
        int count = 0;
        for(int num : nums){
            if(num <= ans) 
                count++;
            else 
                break; // array is sorted
        }
        return ans - count >= k;
    }

    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int l = 1;
        int r = INT_MAX;

        int ans = 0;

        while(l <= r){
            int mid = l + (r - l) / 2;

            if(isAns(arr, k, mid)){
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }

        return ans;
    }
};