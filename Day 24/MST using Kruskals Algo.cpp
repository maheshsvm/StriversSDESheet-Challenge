class DisjointSet{
    vector<int> rank , parent , size;
    public:

    DisjointSet(int n){
        rank.resize(n+1 , 0);
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i = 0; i <= n; i++) parent[i] = i;
    }

    int findUltPar(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUltPar(parent[node]);
    }

    void unionByRank(int u , int v){
        int ulp_u = findUltPar(u);
        int ulp_v = findUltPar(v);

        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u , int v){
        int ulp_u = findUltPar(u);
        int ulp_v = findUltPar(v);

        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }

};


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int , pair<int,int> >> edges;
        DisjointSet ds(V);
        for(int i = 0; i < V; i++){
            for(auto vec : adj[i]){
                int v = vec[0];
                int wt = vec[1];
                edges.push_back({wt , {i , v}});
            }
        }
        
        int wtSum = 0;
        sort(edges.begin() , edges.end());
        
        for(auto& p : edges){
            int wt = p.first;
            int u = p.second.first;
            int v = p.second.second;
            
            if(ds.findUltPar(u) != ds.findUltPar(v)){
                wtSum += wt;
                ds.unionBySize(u , v);
            }
        }
        return wtSum;
    }
};