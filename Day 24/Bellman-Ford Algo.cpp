class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        // Code here
        vector<int> dist(V , 1e8);
        dist[S] = 0;
        
        for(int i = 1; i < V; i++){
            for(auto& edge : edges){
                int u = edge[0];
                int v = edge[1];
                int edgeWt = edge[2];
                if(dist[u] != 1e8 && dist[u] + edgeWt < dist[v]){
                    dist[v] = dist[u] + edgeWt;
                }
            }
        }
        
        // checking for negative wt
        for(auto& edge : edges){
            int u = edge[0];
            int v = edge[1];
            int edgeWt = edge[2];
            if(dist[u] != 1e8 && dist[u] + edgeWt < dist[v]){
                return {-1};
            }
        }
        
        return dist;
    }
};