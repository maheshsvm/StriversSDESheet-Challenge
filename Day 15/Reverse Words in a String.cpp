class Solution {
private:
    void removeSpaces(string &s){
        int startIdx = 0 , cnt = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' '){
                cnt++;
            }
            else{
                if(cnt > 1){
                    s.replace(startIdx , cnt , " ");
                    
                    i -= (cnt - 1);
                }
                startIdx = i + 1;
                cnt = 0;
            }
        }
        // removing trailing spaces if any
        if(cnt > 0){
            s.replace(startIdx , cnt , "");
        }
        // removing leading spaces
        if(s[0] == ' '){
            s.replace(0 , 1 , "");
        }
    }
public:
    string reverseWords(string s) {
        //removing unnecessary spaces
        removeSpaces(s);
        reverse(s.begin() , s.end());
        int startIndex = 0;
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(s[i] == ' '){
                reverse(s.begin() + startIndex , s.begin() + i);
                startIndex = i + 1;
            }
        }
        reverse(s.begin() + startIndex , s.end());

        return s;
    }
};