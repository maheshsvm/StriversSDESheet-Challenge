class Solution {
private:
    int solve(int i , int j , vector<vector<int>>& grid , vector<vector<int>>& dp){
        if(i == 0){
            int sum = 0;
            for(int k = 0; k <= j; k++) sum += grid[i][k];
            return sum;
        }
        if(j == 0){
            int sum = 0;
            for(int k = 0; k <= i; k++) sum += grid[k][j];
            return sum;
        }

        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = grid[i][j] + min(solve(i-1 , j , grid , dp) , solve(i , j-1 , grid , dp));
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m , vector<int>(n , -1));
        return solve(m-1 , n-1 , grid , dp);
    }
};