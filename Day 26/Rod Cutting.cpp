class Solution {
private:
    int solve(int i , int j , vector<int>& modifiedCuts , vector<vector<int>>& dp){
        if(j < i) return 0;

        if(dp[i][j] != -1) return dp[i][j];
        int mini = 1e9;
        for(int cut = i; cut <= j; cut++){
            mini = min(mini , (modifiedCuts[j+1] - modifiedCuts[i-1]) + solve(i , cut-1 , modifiedCuts , dp) + solve(cut+1 , j , modifiedCuts , dp));
        }

        return dp[i][j] = mini;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin() , cuts.end());

        // creating modified cuts array
        int m = cuts.size();
        vector<int> modifiedCuts;
        modifiedCuts.emplace_back(0);
        for(int a : cuts){
            modifiedCuts.emplace_back(a);
        }
        modifiedCuts.emplace_back(n);

        vector<vector<int>> dp(m+3 , vector<int>(m+3 , -1));

        return solve(1 , m , modifiedCuts , dp);
    }
};