class Solution {
public:
    int minMoves2(vector<int>& nums) {
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int mid = nums[n/2];
        int moves = 0;
        for(int& val : nums)
        {
            moves += abs(val - mid);
        }
        return moves;
    }
};