class Solution {
public:
    typedef long long ll;
    int M = 1e9 + 7;
    int maximumXorProduct(long long a, long long b, int n) {
        long long xorA = 0;
        long long xorB = 0;
        for(int i = 49; i >= n; i--){
            bool aBit = ((a >> i) & 1) > 0;
            bool bBit = ((b >> i) & 1) > 0;

            if(aBit){
                xorA = xorA ^ (1ll << i);
            }
            if(bBit){
                xorB = xorB ^ (1ll << i);
            }
        }

        for(int i = n-1; i >= 0; i--){
            bool aBit = ((a >> i) & 1) > 0;
            bool bBit = ((b >> i) & 1) > 0;
            if(aBit == bBit){
                xorA = xorA ^ (1ll << i);
                xorB = xorB ^ (1ll << i);
                continue;
            }
            if(xorA > xorB){
                xorB = xorB ^ (1ll << i);
            }
            else{
                xorA = xorA ^ (1ll << i);
            }
        }
        xorA = xorA % M;
        xorB = xorB % M;
        return ((xorA * xorB)%M);
    }
};