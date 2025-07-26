class Solution {
public:
    long long solve(vector<int>& piles, int m){
        long long ans = 0;
        for(int i = 0; i < piles.size(); i++){
            ans += (piles[i]/m) + (int)(piles[i]%m != 0);
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());

        while(l <= r){
            int m =  l + (r - l)/2;
            if(solve(piles, m) <= h){
                r = m - 1;
            }
            else l = m + 1;
        }
        return l;
    }
};
// 3,6,7,11
// l= 4
// r= 3
// m = 6, 3, 4, 
// 1, 1, 1
// h = 5
// l = 1
// h = 1
// m = 
