//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
        int n= grid.size();
        int m= grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        vector<vector<int>> dis(n, vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(grid[i][j]==1){
                   q.push({{i,j},0});
                   vis[i][j]=1;
                }
            }
        } 
        int newRow[4]={+1,-1,0,0};
        int newCol[4]={0,0,+1,-1};   
        
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int steps= q.front().second;
            q.pop();
            dis[row][col]= steps;
    	      for(int i=0;i<4; ++i){
                int x= row + newRow[i];
                int y= col + newCol[i];
                
                if(x>=0 && y>=0 && x<n && y<m && !vis[x][y]){
                    q.push({{x, y}, steps + 1});
                    vis[x][y] = 1;
                }
            }
        }
    return dis;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends