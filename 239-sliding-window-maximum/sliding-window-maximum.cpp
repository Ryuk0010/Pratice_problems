class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        int n = nums.size();
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(dq.empty()) dq.push_back(i);
            while(!dq.empty() && nums[i] >= nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
             if(!dq.empty() && dq.front()==i-k){
                dq.pop_front();
            }
            if(i >= k-1){
                int temp = dq.front();
                ans.push_back(nums[temp]);
            } 
        }
        return ans;
    }
};