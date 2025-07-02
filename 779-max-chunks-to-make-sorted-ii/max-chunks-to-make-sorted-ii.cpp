class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int>pre(n), suf(n);

        pre[0] = arr[0];
        suf[n-1] = arr[n-1];
        for(int i=1;i<arr.size();i++){
            pre[i] = max(pre[i-1],arr[i]);
            suf[n-i-1] = min(suf[n-i],arr[n-i-1]);
        }
        // for(int i=n-2;i>=0;i--){
        //     suf[i] = min(suf[i+1],arr[i]);
        // }
        int count = 0;
        for(int i=0;i<n-1;i++){
            if(pre[i]<=suf[i+1]) count++;
        }
        return count+1;
    }
};