class Solution {
public:
    void floid(vector<vector<int>>& dist, int n){
        for(int via = 0; via < n; via++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    
                    dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                    if(i == j) dist[i][j] = 0;
                }
            }
        }
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, 1e4 + 1));
        
        for(auto it: edges){
            int src = it[0];
            int dest = it[1];
            int wt = it[2];
            dist[src][dest] = wt;
            dist[dest][src] = wt;
        }
        floid(dist, n);


        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << dist[i][j] << " ";
            }
            cout << endl;
        }

        int ans = -1;
        int miniCity = INT_MAX;
        for(int i = 0; i < n; i++){
            int cnt = 0;
            for(int j = 0; j < n; j++){
                if(i != j && dist[i][j] <= distanceThreshold){
                   cnt++;
                }

            }
            if(cnt <= miniCity){
                miniCity = cnt;
                ans = i;
            }
        }

    return ans;
    }
};