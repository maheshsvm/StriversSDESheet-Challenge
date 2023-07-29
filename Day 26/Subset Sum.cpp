class Solution{   
private:
    bool solve(int n , vector<int>& arr, int sum){
        if(sum < 0) return false;
        if(sum == 0) return true;
        if(n == 0) return false;
        return solve(n - 1 , arr , sum - arr[n-1]) || solve(n-1 , arr , sum);
    }
public:
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        vector<vector<bool>> dp(n+1 , vector<bool>(sum + 1 , false));
        
        for(int i = 0; i <= n; i++){
            dp[i][0] = true;
        }
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= sum; j++){
                if(j - arr[i-1] < 0) dp[i][j] = dp[i-1][j];
                else dp[i][j] = dp[i-1][j - arr[i-1]] || dp[i-1][j];
            }
        }
        
        return dp[n][sum];
    }
};