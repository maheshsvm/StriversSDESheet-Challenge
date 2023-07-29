class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        int vis[V] = {0};
        vector<int> ans;
        queue<int> q;
        q.push(0);
        vis[0] = true;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(int adjNode : adj[node]){
                if(!vis[adjNode]){
                    vis[adjNode] = true;
                    q.push(adjNode);
                }
            }
        }
        return ans;
    }
};