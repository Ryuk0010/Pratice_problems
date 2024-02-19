class Solution {
public:
    int bestClosingTime(string customers) {
      int maxi = 0;
      int sum = 0, ans = 0;
      for(int i = 0; i < customers.size(); i++){
        if(customers[i] == 'Y'){
          sum += 1;
          if(sum > maxi){
            maxi = sum;
            ans = i + 1;
          }
        }
        else{
          sum -= 1;
        }
      }
      // if(sum < 0) return count;
      return ans;
    }
};