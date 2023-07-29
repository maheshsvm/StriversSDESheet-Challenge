class Solution {
private:
    int drow[4] = {0,-1,0,1};
    int dcol[4] = {-1,0,1,0};

    void dfs(int row , int col , int m , int n , vector<vector<char>>& grid , vector<vector<bool>>& vis){
        vis[row][col] = true;

        // checking in four direction
        for(int i = 0; i < 4; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] == '1' && !vis[nrow][ncol]){
                dfs(nrow , ncol , m , n , grid , vis);
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m , vector<bool>(n , false));
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    ans++;
                    dfs(i , j ,m , n, grid , vis);
                }
            }
        }
        return ans;
    }
};