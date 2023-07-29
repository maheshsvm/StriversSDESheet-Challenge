class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int n, int k) 
    {
       vector<int> dp(n + 1, 0);
        int moves = 0;
        while(dp[n] < k) {
            moves++;
            for(int i = n; i > 0; i--) dp[i] += 1 + dp[i-1];
        }
        return moves;
    }
};