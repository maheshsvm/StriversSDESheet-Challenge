class Solution {
public:
    string longestPalindrome(string s) {
        int maxStart = 0 , maxLen = 1;
        int n = s.size();

        //checking for odd size palindromes
        for(int i = 1; i < n - 1; i++){
            int l = i - 1 , r = i + 1;
            while(l >= 0 && r < n && s[l] == s[r]){
                l--; r++;
            }
            int lenOfPalindrome = r - l - 1;
            if(lenOfPalindrome > maxLen){
                maxStart = l + 1;
                maxLen = lenOfPalindrome;
            }
        }

        // for even length palindromes
        for(int i = 0; i < n - 1; i++){
            int l = i , r = i + 1;
            while(l >= 0 && r < n && s[l] == s[r]){
                l--; r++;
            }
            int lenOfPalindrome = r - l - 1;
            if(lenOfPalindrome > maxLen){
                maxStart = l + 1;
                maxLen = lenOfPalindrome;
            }
        }
        return s.substr(maxStart , maxLen);
    }
    
};