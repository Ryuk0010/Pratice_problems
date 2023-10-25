//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    class DisjointSet
    {
    private:
        vector<int> SIZE,PARENT;
    public:
        DisjointSet(int n)
        {
            SIZE.resize(n+1,1);
            PARENT.resize(n+1);
            for(int i=0; i<=n; i++)
                PARENT[i] = i;
        }
        int findUParent(int NODE)
        {
            if(PARENT[NODE] == NODE) return NODE;
            return PARENT[NODE] = findUParent(PARENT[NODE]);
        }
        void unionBySize(int NODE_1,int NODE_2)
        {
            int prnt_1 = findUParent(NODE_1);
            int prnt_2 = findUParent(NODE_2);
            if(prnt_1 == prnt_2) return;
            if(SIZE[prnt_1] < SIZE[prnt_2])
            {
                PARENT[prnt_1] = prnt_2;
                SIZE[prnt_2] += SIZE[prnt_1];
            }
            else
            {
                PARENT[prnt_2] = prnt_1;
                SIZE[prnt_1] += SIZE[prnt_2];
            }
        }
    };
	public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int,pair<int,int>>> edges;
        for(int i=0; i<V; i++) 
            for(auto it : adj[i])
            {
                int node = i;
                int u = it[0];
                int wt = it[1];
                edges.push_back({wt,{node,u}});
            }
        
        sort(edges.begin(),edges.end());
        DisjointSet DS(V);
        int mst_wt = 0;
        for(auto it : edges)
        {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            if(DS.findUParent(u) != DS.findUParent(v))
            {
                mst_wt += wt;
                DS.unionBySize(u,v);
            }
        }
        return mst_wt;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends