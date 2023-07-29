class Solution {
private:
    bool dfs(int node , int currentColor ,  vector<vector<int>>& graph , vector<int>& color){
        color[node] = currentColor;

        for(int adjNode : graph[node]){
            if(color[adjNode] == -1){
                if(!dfs(adjNode , !currentColor , graph , color)) return false;
            }
            else if(color[adjNode] == currentColor) return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n , -1);

        for(int i = 0; i < n; i++){
            if(color[i] == -1){
                if(!dfs(i , 0 ,  graph , color)) return false;
            }
        }
        return true;
    }
};