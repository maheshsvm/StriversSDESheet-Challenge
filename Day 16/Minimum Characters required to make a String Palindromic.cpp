vector<int> constructLPS(string& s){
    int n = s.size();
    vector<int> lps(n , 0);
    int len = 0;
    for(int i = 1; i < n; i++){
        if(s[len] == s[i]){
            len++;
            lps[i] = len;
        }
        else{
            if(len != 0){
                len = lps[len - 1];
                i--;
            }else{
                lps[i] = 0;
            }
        }
    }
    return lps;
}
    
int Solution::solve(string str) {
            string newStr = str + '$';
        reverse(str.begin() , str.end());
        newStr += str;
        vector<int> lps = constructLPS(newStr);
        return str.size() - lps[lps.size() - 1];
}
