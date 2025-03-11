class Solution {
public:
	int f(int i,int j,vector<int>& cuts, vector<vector<int>>& dp){
		if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
		int mini=1e9;

		for(int ind=i;ind<=j;ind++){
			int cost= cuts[j+1]-cuts[i-1]+f(i,ind-1,cuts, dp)+f(ind+1,j,cuts, dp);
			mini=min(mini,cost);
		}
		return dp[i][j] = mini;
	}

	int minCost(int n, vector<int>& cuts) {
		cuts.insert(cuts.begin(),0);
		cuts.insert(cuts.end(),n);
		sort(cuts.begin(),cuts.end());
        int m=cuts.size();
        vector<vector<int>> dp(m+1,vector<int>(m+1,-1));
		return f(1,cuts.size()-2,cuts, dp);
	}
};