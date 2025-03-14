class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        for(int i = 1; i < n-1; i++){
            if(arr[i] > arr[i-1] && arr[i] > arr[i+1]){
                int s = i, e = i;
                while(s > 0 && arr[s] > arr[s-1]) s--;
                while(e < n-1 && arr[e] > arr[e+1]) e++;
                ans = max(ans, e-s+1);
                i = e;
            }
            
        }
        return ans;
    }
};