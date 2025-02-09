class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:flights){
           adj[it[0]].push_back({it[1],it[2]});

        }
        vector<int>price(n,INT_MAX);
        price[src]=0;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
        q.push({0,{src,0}});
        while(!q.empty()){
            int stop=q.top().first;
            int node=q.top().second.first;
            int cost=q.top().second.second;
            q.pop();

            if(stop > k){
               continue; 
            }

            for(auto it: adj[node]){
             
              if(stop <= k && cost + it.second < price[it.first]){
                 price[it.first] = cost + it.second;
                  q.push({stop + 1, {it.first, cost + it.second}});
              }
            }
        }
        return price[dst] == INT_MAX ? -1: price[dst];
    }
};