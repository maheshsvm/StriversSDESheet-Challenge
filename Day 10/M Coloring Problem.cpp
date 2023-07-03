class Solution{
private:
    bool isPossible(int color , int vertex , int n , vector<int>& colorAtVertex , bool graph[101][101]){
        for(int i = 0; i < n; i++){
            if(graph[vertex][i] == 1 && colorAtVertex[i] == color){
                return false;
            }
        }
        return true;
    }
    bool solve(int vertex , int n , int m , vector<int>& colorAtVertex , bool graph[101][101]){
        if(vertex == n) return true;
        for(int color = 1; color <= m; color++){
            if(isPossible(color , vertex , n , colorAtVertex , graph)){
                colorAtVertex[vertex] = color;
                if(solve(vertex + 1 , n , m , colorAtVertex , graph) == true){
                    return true;
                }
                
                colorAtVertex[vertex] = 0;
            }
        }
        return false;
    }
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        vector<int> colorAtVertex(n , 0);
        return solve(0 , n , m , colorAtVertex , graph);
    }
};