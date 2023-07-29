class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> ans;
        vector<int> vis(V , false);
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                dfs(i , adj , vis , ans);
            }
        }
        return ans;
    }
    
    void dfs(int node , vector<int> adj[] , vector<int>&vis , vector<int>&ans){
        ans.push_back(node);
        vis[node] = true;
        
        for(int adjNode : adj[node]){
            if(!vis[adjNode]){
                // vis[adjNode] = true;
                dfs(adjNode , adj , vis , ans);
            }
        }
    }
};