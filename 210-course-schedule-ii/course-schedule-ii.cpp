class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
      int n = pre.size();
      vector<int> adj[numCourses];
      vector<int> indegree(numCourses, 0);
      queue<int> q;
      for (auto it : pre){
          adj[it[1]].push_back(it[0]);
      }
      for (int i = 0; i < numCourses; i++){
          for (int adjNode : adj[i]){
            indegree[adjNode]++;
          }
        }
      for(int i = 0; i < numCourses; i++){
        if(indegree[i] == 0)q.push(i);
      }
      vector<int> ans;
      while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for(auto it: adj[node]){
          indegree[it]--;
          if(indegree[it] == 0){
            q.push(it);
          }
        }
      }
      if(ans.size() == numCourses) return ans;
      else return {};
      
    }
};