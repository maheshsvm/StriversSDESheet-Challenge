class Solution {
private:
    bool solve(int idx , string& s, unordered_set<string>& st , vector<int>&dp){
        if(idx == s.size()) return true;
        if(dp[idx] != -1) return dp[idx];
        for(int i = idx; i < s.size(); i++){
            if(st.find(s.substr(idx , i - idx+1)) != st.end()){
                if(solve(i+1 , s , st , dp)) return true;
            }
        }
        return dp[idx] = false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size() , true);
        dp[s.size() - 1] = true;
        unordered_set<string> st(wordDict.begin() , wordDict.end());

        for(int idx = s.size()-1; idx >= 0; idx--){
            for(int i = idx; i < s.size()-1; i++){
                if(st.find(s.substr(idx , i - idx+1)) != st.end()){
                    if(dp[i+1]) return true;
                }
            }
            dp[idx] = false;
        }
        return dp[0];
        // return solve(0 ,s , st , dp);
    }
};