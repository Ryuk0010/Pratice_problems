class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indeg(numCourses, 0);
        for(int i = 0; i < prerequisites.size(); i++){
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            adj[b].push_back(a);
            indeg[a]++;
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indeg[i] == 0)q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            int ele = q.front();
            ans.push_back(ele);
            q.pop();
            for(auto it: adj[ele]){
                indeg[it]--;
                if(indeg[it] == 0){
                    q.push(it);
                }
            }
        }
        return (ans.size() == numCourses)? ans : vector<int> {};
    }
};