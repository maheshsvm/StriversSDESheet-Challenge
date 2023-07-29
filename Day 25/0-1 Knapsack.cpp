class Solution
{
    private:
    int solve(int i , int W , int wt[] , int val[] , vector<int>& dp){
        if(i < 0) return 0;
        if(W <= 0) return 0;
        
        int notTake = solve(i-1 , W , wt , val , dp);
        int take = 0;
        if(wt[i] <= W){
            take = val[i] + solve(i-1 , W - wt[i] , wt , val , dp);
        }
    }
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    {
        return solve(n-1 , W , wt , val , dp);
    }
};