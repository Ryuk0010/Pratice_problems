class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites){
      vector<int> adj[numCourses];
      for (auto it : prerequisites){
          adj[it[1]].push_back(it[0]);
      }
      int V = numCourses;
        vector<int> indegree(V, 0);
        for (int i = 0; i < V; i++){
          for (int adjNode : adj[i]){
            indegree[adjNode]++; // calculating indegree of every node
          }
        }
        queue<int> q;
        for (int i = 0; i < V; i++){
          if (indegree[i] == 0){
            q.push(i); // pushing starting sources
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
        if (topo.size() == V){
          return true;
        }

      return false;
    }
};