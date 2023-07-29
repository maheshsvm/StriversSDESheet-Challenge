class Solution {
private:
    int solve(int i , int j , string&s , string& t){

        if(i < 0) return j+1;
        if(j < 0) return i + 1;
        if(s[i] == t[j]) return solve(i-1 , j-1, s , t);
        return 1 + min( solve(i-1 ,j , s , t) , min( solve(i , j-1 , s , t) , solve(i-1 , j -1 ,s ,t) ) );
    }
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        return solve(m-1 , n-1 , word1 , word2);
    }
};