class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // vector<vector<bool>> vis(m , vector<bool>(n , false));
            int drow[4] = {0,-1,0,1};
            int dcol[4] = {-1,0,1,0};
        int ans = 0;
        queue<pair<int , int>> q;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2) q.push({i , j});
            }
        }

        while(!q.empty()){
            int size = q.size();
            while(size--){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                for(int i = 0; i < 4; i++){
                    int nrow = row + drow[i];
                    int ncol = col + dcol[i];
                    if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] == 1){
                        grid[nrow][ncol] = 2;
                        q.push({nrow , ncol});
                    }
                }
            }
            if(!q.empty()) ans++;
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j< n; j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        return ans;
    }
};