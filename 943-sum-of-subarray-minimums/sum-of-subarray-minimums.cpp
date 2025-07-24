class Solution {
public:
const int MOD = 1e9 + 7;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> l(n), r(n);
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
            l[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        st = stack<int>();
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            r[i] = st.empty() ? n : st.top();
            st.push(i);
        }   
        long long ans = 0;
        for(int i = 0; i < n; i++){
            long long d = ((r[i] - i) * (i - l[i])) % MOD;
            long long s = (d * arr[i]) % MOD;
            ans = (ans + s) % MOD;
        }  
        return (int)ans;   
    }
};