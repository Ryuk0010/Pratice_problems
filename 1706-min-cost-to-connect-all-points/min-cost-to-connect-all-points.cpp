class Solution {
public:
    class DisjointSet{
        public :
        vector<int>parent ;
        vector<int>size ; 

        DisjointSet(int n)
        {
            parent.resize(n+1,0) ;
            size.resize(n+1,0) ;

            for(int i=0 ; i<=n ; i++)
            {
                parent[i]=i ;
                size[i]=1 ;
            }
        }

        int findUPar(int u)
        {
            if(u==parent[u]) return u ;

            return parent[u]=findUPar(parent[u]) ;
        }

        void UnionBySize(int u , int v)
        {
            int ulp_u = findUPar(u) ;
            int ulp_v = findUPar(v) ;

            if(ulp_u==ulp_v) return ;

            if(size[ulp_u]<=size[ulp_v])
            {
                size[ulp_u]+=size[ulp_v] ;
                parent[ulp_u]=ulp_v ;
            }
            else
            {
                size[ulp_v]+=size[ulp_u] ;
                parent[ulp_v]=ulp_u ;
            }
        }
    };
    int Kruskal(vector<vector<int>>& edges)
    {
        int n = edges.size() ;
        DisjointSet ds(n) ;

        int sum = 0 ;

        auto lambda = [&](vector<int>&vec1,vector<int>&vec2)
        {
            return vec1[2]<vec2[2] ;
        };

        sort(edges.begin(),edges.end(),lambda) ;

        for(int i=0 ; i<n ; i++)
        {
            int u = edges[i][0] ;
            int v = edges[i][1] ;
            int wt = edges[i][2] ;

            if(ds.findUPar(u)!=ds.findUPar(v))
            {
                ds.UnionBySize(u,v) ;
                sum+=wt ;
            }
        }

        return sum ;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>>edges ;
        for(int i=0 ; i<points.size() ; i++)
        {
            for(int j=i+1 ; j<points.size() ; j++)
            {
                int dist = abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                edges.push_back({i,j,dist}) ;
            }
        }

        return Kruskal(edges) ;
    }
};