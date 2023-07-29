class Solution{
		
    private:
    int solve(int i , int prev , int arr[] , int n , vector<vector<int>>& dp){
        if(i == n) return 0;
        if(dp[i][prev+1] != -1) return dp[i][prev+1];
        int notTake = solve(i+1 , prev , arr , n , dp);
        int take = -1;
        if(prev == -1 || arr[i] > arr[prev]) take = arr[i] + solve(i+1 , i , arr , n , dp);
        return dp[i][prev+1] =  max(take , notTake);
    }
	public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    vector<vector<int>> dp(n , vector<int>(n+1 , -1));
	    return solve(0 , -1 , arr , n , dp);
	}  
};