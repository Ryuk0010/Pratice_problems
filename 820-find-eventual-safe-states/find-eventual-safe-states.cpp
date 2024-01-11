class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
      vector<int> adj[graph.size()];
      vector<int> deg(graph.size(), 0);
      for(int i = 0; i < graph.size(); i++){
       
        for(auto it: graph[i]){
          adj[it].push_back(i); 
          deg[i]++;
        }
      }
      queue<int> q;
      for(int i = 0; i < deg.size(); i++){
        if(deg[i] == 0) q.push(i);
      }
      vector<int> ans;
      while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for(auto it: adj[node]){
          deg[it]--;
          if(deg[it] == 0) q.push(it);
        }
      }
      sort(ans.begin(), ans.end());
      return ans;
    }
};