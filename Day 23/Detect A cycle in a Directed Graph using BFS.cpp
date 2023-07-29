class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int indeg[V] = {0};
        queue<int> q;
        for(int i = 0; i < V; i++){
            for(int ele : adj[i]){
                indeg[ele]++;
            }
        }
        
        for(int i = 0; i < V; i++){
            if(indeg[i] == 0) q.push(i);
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(int adjNode : adj[node]){
                indeg[adjNode]--;
                if(indeg[adjNode] == 0) q.push(adjNode);
            }
        }
        
        for(int i = 0; i < V; i++){
            if(indeg[i] > 0) return true;
        }
        
        return false;
    }
};