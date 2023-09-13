//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	   void solve(int index, string S, set<string>&ans) {
        if(index == S.size()) {
            ans.insert(S);
            return;
        }
        for(int i=index; i<S.size();i++) {
            swap(S[index],S[i]);
            solve(index+1,S,ans);
            swap(S[index],S[i]);
        }
        
    }
        vector<string>find_permutation(string S)
        {
           set<string>ans;
            solve(0,S,ans);
           vector<string>result(ans.begin(),ans.end());
           return result;
           
        }
};


//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends