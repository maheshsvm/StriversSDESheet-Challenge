class Solution {
private:
    int solve(int i , int j , string& s , string& t,vector<vector<int>>& dp){
        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == t[j]){
            return 1 + solve(i-1 , j-1 , s , t , dp);
        }

        return dp[i][j] =  max(solve(i,j-1 , s , t , dp)  , solve(i-1 , j , s , t , dp));
    }
public:
    int longestCommonSubsequence(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<vector<int>> dp(m+1 , vector<int>(n+1 , 0));

        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] =  1 + dp[i-1][j-1];
                }

                else dp[i][j] =  max(dp[i][j-1]  , dp[i-1][j]);
            }
        }
        return dp[m][n];
        // return solve(m-1 , n-1 , text1 , text2 , dp);
    }
};