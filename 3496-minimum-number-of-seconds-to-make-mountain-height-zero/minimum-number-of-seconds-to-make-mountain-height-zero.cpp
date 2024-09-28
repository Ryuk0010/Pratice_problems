#define ll long long
class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) 
    {
        ll l=0;
        ll r=1e18;
        ll ans=r;
        while(l<=r)
        {
            ll mid=(l+r)/2ll;
            ll sm=0;
            for(int i=0;i<workerTimes.size();i++)
            {
                ll val=(mid*2ll)/(workerTimes[i]*1ll);
                val*=4ll;
                val++;
                val=sqrtl(val);
                val--;
                val/=2ll;
                sm+=max(0ll,val);
            }
            if(sm>=mountainHeight)
            {
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;

    }
};