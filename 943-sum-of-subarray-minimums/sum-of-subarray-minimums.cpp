class Solution {
public:
    const int MOD = 1e9 + 7;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n, 0), right(n, 0);
        stack<pair<int, int>> st;
        for(int i = 0; i < n; i++){
            int cnt = 1;
            while(!st.empty() && st.top().first > arr[i]){
                cnt += st.top().second;
                st.pop();
            }
            st.push({arr[i], cnt});
            left[i] = cnt;
        }
        st = stack<pair<int, int>>();
        for(int i = n-1; i >= 0; i--){
            int cnt = 1;
            while(!st.empty() && st.top().first >= arr[i]){
                cnt += st.top().second;
                st.pop();
            }
            st.push({arr[i], cnt});
            right[i] = cnt;
        }
        long long ans = 0;
        for(int i = 0; i < n; i++){
            long long l = left[i] % MOD;
            long long r = right[i] % MOD;
            long long prod = (l * r) % MOD;
            prod = (prod * arr[i]) % MOD;
            ans = (ans + prod) % MOD;

        }
        return (int)ans;
    }
};