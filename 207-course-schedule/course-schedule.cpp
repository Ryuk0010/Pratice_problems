class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        for(auto it: prerequisites){
            adj[it[1]].push_back(it[0]);
        }
          for (auto adjNode : prerequisites){
            indegree[adjNode[0]]++; 
          }
        
        queue<int> q;
        for (int i = 0; i < numCourses; i++){
          if (indegree[i] == 0){
            q.push(i); 
          }
        }

        vector<int> topo;
        while (!q.empty()){
          int node = q.front();
          q.pop();
          topo.push_back(node);
          for (int adjNode : adj[node]){
            indegree[adjNode]--;
            if (indegree[adjNode] == 0){
              q.push(adjNode);
            }
          }
        }
        if (topo.size() == numCourses){
          return true;
        }
        return false;
    }
};