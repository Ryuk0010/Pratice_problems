class Solution {
public:
    void checkFactor(unordered_set<int> &st, int n){
        for(int i = 2; i*i <= n; i++){
            while(n%i == 0){
                st.insert(i);
                n /= i;
            }
        }
        if(n > 1) st.insert(n);
    }
    int distinctPrimeFactors(vector<int>& nums) {
        unordered_set<int> st;
        for(int i = 0; i < nums.size(); i++){
            checkFactor(st, nums[i]);
        }
        return st.size();
    }
};