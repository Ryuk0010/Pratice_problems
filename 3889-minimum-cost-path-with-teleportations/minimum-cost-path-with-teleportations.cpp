class Solution {
public:

    int minCost(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size();
        vector<tuple<int,int,int>> val;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                val.push_back({grid[i][j],i,j});
            }
        }
        sort(val.begin(),val.end());
        vector<vector<vector<int>>> dist(k+1,vector<vector<int>>(m,vector<int>(n,1e9)));
        priority_queue<tuple<int,int,int,int>,vector<tuple<int,int,int,int>>,greater<tuple<int,int,int,int>>> pq;
        pq.push({0,0,0,0});
        dist[0][0][0]=0;
        vector<int> ptr(k+1,0);
        while(!pq.empty()){
            auto state=pq.top();
            pq.pop();
            int cost=get<0>(state);
            int i=get<1>(state);
            int j=get<2>(state);
            int tp=get<3>(state);
            int ind=ptr[tp];
            if(cost!=dist[tp][i][j]) continue;
            if(i==m-1 && j==n-1) return cost;
            while(ind<val.size() && get<0>(val[ind])<=grid[i][j]){
                int a=get<1>(val[ind]);
                int b=get<2>(val[ind]);
                if(tp<k && dist[tp+1][a][b]>cost){
                    dist[tp+1][a][b]=cost;
                    pq.push({cost,a,b,tp+1});
                }
                ind++; 
            }
            ptr[tp] = ind;
            if(i+1<m && dist[tp][i+1][j]>cost+grid[i+1][j]){
                dist[tp][i+1][j]=cost+grid[i+1][j];
                pq.push({dist[tp][i+1][j],i+1,j,tp});
            }
            if(j+1<n && dist[tp][i][j+1]>cost+grid[i][j+1]){
                dist[tp][i][j+1]=cost+grid[i][j+1];
                pq.push({dist[tp][i][j+1],i,j+1,tp});
            }
        }
        return -1;
    }
};