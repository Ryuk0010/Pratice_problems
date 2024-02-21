class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 0 || num == 1) return true;
        int start = 1;
        int end = num;
        while(start <= end){
            int mid = start + ((end - start) / 2);
            if(num % mid == 0 && mid == num / mid) return true;
            else if(mid > num / mid){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        return false;
    }
};