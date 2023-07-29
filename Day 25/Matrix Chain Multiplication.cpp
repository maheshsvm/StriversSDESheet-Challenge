// User function Template for C++

class Solution{
private:
    int solve(int i , int j , int arr[] , vector<vector<int>>& dp){
        if(i == j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = INT_MAX;
        
        for(int k = i; k < j; k++){
            int rec = solve(i , k , arr , dp) + solve(k+1 , j , arr , dp);
            int steps = arr[i-1]*arr[k]*arr[j];
            ans = min(ans , steps + rec);
        }
        return dp[i][j] = ans;
    }
public:
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> dp(N , vector<int>(N , -1));
        return solve(1 , N-1 , arr , dp);
    }
};