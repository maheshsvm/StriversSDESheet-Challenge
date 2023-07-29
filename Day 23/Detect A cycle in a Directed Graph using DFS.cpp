class Solution {
  private:
    bool dfs(int node , int parent , vector<int> adj[] , vector<bool> &vis , vector<bool> &pathVis){
        vis[node] = true;
        pathVis[node] = true;
        for(int adjNode : adj[node]){
            if(!vis[adjNode]){
                if(dfs(adjNode , node , adj , vis , pathVis) == true) return true;
            }
            else if(pathVis[adjNode]) return true;
        }
        pathVis[node] = false;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool> vis(V , false);
        vector<bool> pathVis(V , false);
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                if(dfs(i , -1 , adj , vis , pathVis) == true) return true;
            }
        }
        
        return false;
    }
};