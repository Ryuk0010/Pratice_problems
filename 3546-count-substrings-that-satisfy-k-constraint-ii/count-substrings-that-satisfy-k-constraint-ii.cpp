class Solution {
public:
    vector<long long> countKConstraintSubstrings(string s, int k, vector<vector<int>>& queries) {
        int n = s.size();
        vector<long long> valid_btw_lTOr(n, 0);
        vector<long long> prefix_sum(n, 0);
        vector<long long> ans;
        long long left = 0, one = 0, zero = 0;
        prefix_sum[0] = 1;
        for(long long right = 0; right < n; right++){
            if(s[right] == '1') one++;
            if(s[right] == '0') zero++;
            while(one > k && zero > k){
                if(s[left] == '1') one--;
                if(s[left] == '0') zero--;
                left++;
            }
            valid_btw_lTOr[right] = left;
        }
        for(long long i = 1; i < n; i++){
            long long len = (i - valid_btw_lTOr[i]+1);
            prefix_sum[i] = prefix_sum[i-1] + len;
        }


        for(auto &q : queries){
            long long l = q[0];
            long long r = q[1];

            
            long long firstPos = r+1, result = 0;
            while(l <= r){
                long long mid = (r + l)/2;
                if(valid_btw_lTOr[mid] >= q[0]){
                    firstPos = mid;
                    r = mid - 1;
                }
                else l = mid+1;
            }

            if(firstPos <= q[1]){
                result += prefix_sum[q[1]];
                if(firstPos > 0){
                    result -= prefix_sum[firstPos-1];
                }
            }
            long long diff = firstPos - q[0];
            result += ((diff) * (diff+1))/2;
            ans.push_back(result);
        }
        return ans;
    }
};