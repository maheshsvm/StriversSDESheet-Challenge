#include<bits/stdc++.h>
bool bfs(int start , vector<int> adj[] , vector<bool>& vis){
    queue<pair<int,int>> q;
    vis[start] = true;
    q.push({start , -1});

    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(int it : adj[node]){
            if(!vis[it]){
                vis[it] = true;
                q.push({it , node});
            }
            else if(it != parent){
                return true;
            }
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

    for(int i = 1; i <=n; i++){
        if(!vis[i]){
            if(bfs(i , adj , vis)) return "Yes";
        }
    }
    return "No";

}
