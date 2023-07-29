class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // initialization
        int m = image.size();
        int n = image[0].size();
        vector<vector<bool>> vis( m , vector<bool>(n , false));
        vector<vector<int>> ans(image);
        queue<pair<int , int>> q;
        int drow[] = {0,-1,0,1};
        int dcol[] = {-1,0,1,0};

        q.push({sr , sc});
        ans[sr][sc] = color;
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && image[row][col] == image[nrow][ncol] && !vis[nrow][ncol]){
                    ans[nrow][ncol] = color;
                    vis[nrow][ncol] = true;
                    q.push({nrow , ncol});
                }
            }
        
        }
        return ans;
    }
};