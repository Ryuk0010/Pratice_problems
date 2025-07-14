class Solution {
public:
    int findPivot(vector<int>& nums, int s, int e){
        int randomIdx = s + rand() % (e - s + 1);
        swap(nums[s], nums[randomIdx]);
        if (s >= e) return -1;
        int p = s;
        int l = s+1;
        int h = e;
        while (l <= h) {
            while (l <= e && nums[l] <= nums[p]) l++;
            while (h > s && nums[h] > nums[p]) h--;
            if (l < h) swap(nums[l], nums[h]);
        }
        swap(nums[p], nums[h]);
        return h;
    }
    void QuickSort(vector<int>& nums, int s, int e){
        if(s >= e) return;

        int pivot = findPivot(nums, s, e);
        QuickSort(nums, s, pivot - 1);
        QuickSort(nums, pivot + 1, e);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        QuickSort(nums, 0, n-1);
        return nums;
    }
};