class Solution {
public:
    int minTime(const string& s, vector<int>& order, int k) {
        int n = s.size();
        long long cnt = 0;
        set<int> st = {-1, n};
        for(int i = 0; i < n; i++) {
            int ind = order[i];
            auto it = st.lower_bound(ind);
            int rightStar = *(it);
            int leftStar = *(--it);
            int len1 = ind - leftStar, len2 = rightStar - ind;
            st.insert(ind);

            cnt += 1LL * len1 * len2;

            if(cnt >= k) return i;
        }
        return -1;
    }
};