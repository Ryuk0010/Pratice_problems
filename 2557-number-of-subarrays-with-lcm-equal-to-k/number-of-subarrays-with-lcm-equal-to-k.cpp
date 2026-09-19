class Solution {
public:
    long long gcd(long long a,long long b){return b==0?a:gcd(b,a%b);}
    long long lcm(long long a,long long b){return a* (b/gcd(a,b));}


    int subarrayLCM(vector<int>& arr, int k) {
        int n = arr.size();

        int count=0;
        for(int i=0;i<n;++i){
            long long l = arr[i];
            for(int j=i;j<n;++j){
                l = lcm(l, arr[j]);
                if(l>k) break;
                if(l==k) count++;
                
            }
        }
        return count;
        
    }
};