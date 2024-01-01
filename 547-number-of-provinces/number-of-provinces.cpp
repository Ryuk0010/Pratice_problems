class Solution {
public:
    void bfs(int node,vector<int>adj[],vector<int>&vis){
        queue<int>q;
        q.push(node);
        vis[node] = 1;
        while(!q.empty()){
            int nodeval = q.front();
            q.pop();
            for(auto x:adj[nodeval]){
                if(!vis[x]){
                    vis[x] = 1;
                    q.push(x);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected[0].size();
        vector<int>adj[n];
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j] == 1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);               
                }
            }
        }  

        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                bfs(i,adj,vis);
            }
        }
        return cnt;
    }
};