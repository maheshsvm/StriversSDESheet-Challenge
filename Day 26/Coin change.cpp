class Solution {
private:
    int solve(int i , vector<int>&coins , int amount , vector<vector<int>>& dp){
        if(amount == 0) return 0;
        if(i < 0){
            return 1e9;
        }
        if(dp[i][amount] != -1) return dp[i][amount];
        // not take
        int notTake = solve(i-1 , coins , amount , dp);

        // take
        int take = 1e9;
        if(coins[i] <= amount){
            take = 1 + solve(i , coins , amount - coins[i] , dp);
        }
        return dp[i][amount] = min(take , notTake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1 , -1));
        int ans = solve(n-1 , coins , amount , dp);
        return (ans == 1e9?-1 : ans);
    }
};