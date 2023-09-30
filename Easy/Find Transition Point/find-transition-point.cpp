//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int transitionPoint(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n], i;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << transitionPoint(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends


int transitionPoint(int arr[], int n) {
    // code here
    int low = 0;
    int high = n - 1;
    
    int ans = -1;
    if(n == 1 && arr[0] == 1) return 0;
    if(n == 1 && arr[0] == 0) return -1;
    if(arr[n-1] == 0) return -1;
    if(arr[0] == 1 && arr[n-1] == 1) return 0;
    while(low <= high){
        int mid = (low + high)/2;
        if(arr[mid] == 0){
            low = mid + 1;
            
            ans = mid+1;
        }
        else{
            high = mid - 1;
        }
    }
    return ans;
}