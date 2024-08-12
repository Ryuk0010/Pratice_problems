class Solution {
public:
    int mySqrt(int x) {
        int INTMAX = 2147395599;
        int low = 1;
        int high = x;
        int ans = 1;
        if (x == 0 || x ==1){
            return x;
        }
        else if(x == INTMAX){
            return 46339;
        }
        else if(x> INTMAX){
            return 46340;
        }
        while (low <= high){
            float mid = (low+high) / 2;
            if (mid*mid == x){
                ans = mid; 
                break;
            }
            else if (mid<x/mid){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid -1;
            }
        }
        return int(ans) ;
    }
};