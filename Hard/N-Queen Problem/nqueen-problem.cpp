//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
  void solve(int col,vector<vector<int>>& board,vector<int>& leftrow,vector<int>& upperdiag,vector<int>& lowerdiag,int n,vector<vector<int>>& ans,vector<int>& temp){
        if(col==n){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<n;i++){
            if(leftrow[i]==0 && lowerdiag[i+col]==0 && upperdiag[n-1+col-i]==0){
                temp.push_back(i+1);
                leftrow[i]=1;
                lowerdiag[i+col]=1;
                upperdiag[n-1+col-i]=1;
                
                solve(col+1,board,leftrow,upperdiag,lowerdiag,n,ans,temp);
                
                temp.pop_back();
                leftrow[i]=0;
                lowerdiag[i+col]=0;
                upperdiag[n-1+col-i]=0;
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>> ans;
        vector<vector<int>> board(n,vector<int>(n,0));
        vector<int> temp;
        
        vector<int> leftrow(n,0),upperdiag(2*n-1,0),lowerdiag(2*n-1,0);
        
        solve(0,board,leftrow,upperdiag,lowerdiag,n,ans,temp);
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends