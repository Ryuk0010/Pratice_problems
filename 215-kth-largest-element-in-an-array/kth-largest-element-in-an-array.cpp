class Solution {
public:
    int solve(vector<int>& nums, int left, int right, int k){
        if(left == right) return nums[left];

        int s = left;
        int e = right;
        int p = nums[left];

        while(s <= e){
            while(s <= e && nums[s] < p) s++;
            while(s <= e && nums[e] > p) e--;
            if(s <= e){
                swap(nums[s], nums[e]);
                s++;
                e--;
            }
        }
        if(e >= k) return solve(nums, left, e, k);
        else if(s <= k) return solve(nums, s, right, k);
        else return nums[k];
    }
    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size() - k;
        return solve(nums, 0, nums.size()-1, k);
    }
};