using ll = long long;
const int mod = 1e9+7;
class Solution {
public:
    int divisibleGame(vector<int>& nums) {
        set<int> st = {2};
        for(auto x:nums){
            for(int i=2;i*i<=x;i++){
                if(x%i==0){
                    st.insert(i);
                    while(x%i==0) x/=i;
                }
            }
            if(x>1) st.insert(x);
        }

        auto get_sum = [&](int k){
            ll sum=0,ans=-1e9;

            for(auto x:nums){
                if(x%k) x=-x;

                sum+=x;
                ans = max(ans,sum);
                if(sum <0) sum=0;
            }
            return ans;
        };

        int k=2;
        ll max_sum=-1e9;

        for(auto K:st){
            ll sum = get_sum(K);
            if(sum > max_sum){
                max_sum=sum;
                k=K;
            }
        }
        ll ans = (max_sum + mod)%mod * k %mod;
        return ans;
    }   
};