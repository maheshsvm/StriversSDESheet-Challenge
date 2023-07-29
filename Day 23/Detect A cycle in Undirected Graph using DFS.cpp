bool solve(int node , int parent , vector<int> adj[] , vector<bool>& vis){
    vis[node] = true;

    for(int it : adj[node]){
        if(!vis[it]){
            if(solve(it , node , adj , vis)) return true;
        }
        else if(it != parent){
            return true;
        }
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // making adjacancy list
    vector<int> adj[n+1];
    vector<bool> vis(n+1 , false);

    for(auto& edge : edges){
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            if(solve(i , -1 , adj , vis)) return "Yes";
        }
    }

    return "No";

}
