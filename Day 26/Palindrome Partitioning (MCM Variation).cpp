// User function Template for C++

class Solution{
private:
    bool isPalindrome(int i , int j ,string& s){
        while(i < j){
            if(s[i] != s[j]) return false;
            i++ , j--;
        }
        return true;
    }
public:
    int palindromicPartition(string s)
    {
        int n = s.length();
        vector<int> dp(n+1 , 0);

        for(int i = n-1 ; i >= 0; i--){
            int minCost = INT_MAX;
            for(int j = i; j < s.size(); j++){
                if(isPalindrome(i , j , s)){
                    minCost = min(minCost , 1 + dp[j+1]);
                }
            }
            dp[i] = minCost;
        }

        return dp[0] - 1;
    }
};