class Solution {
private:
    bool isPalindrome(string s, int start, int end) {
        while (start <= end) {
        if (s[start++] != s[end--])
            return false;
        }
        return true;
  }

  void solve(int idx , string& s , vector<string>&ds,vector<vector<string>>& ans){
      if(idx == s.size()){
        ans.push_back(ds);
        return;
      }
      for(int i = idx; i < s.size();i++){
          if(isPalindrome(s , idx , i)){
            ds.push_back(s.substr(idx , i - idx + 1));
            solve(i+1 , s , ds , ans);
            ds.pop_back();
          }
      }
  }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> ds;
        solve(0 , s , ds , ans);
        return ans;
    }
};