class Solution {
private:
    string say(string s){
        int n = s.size();
        char ch = s[0];
        int freq = 1;
        string ans = "";
        for(int i = 1; i < s.size(); i++){
            if(ch == s[i]){
                freq++;
            }
            else{
                ans += (to_string(freq) + ch);
                ch = s[i];
                freq = 1;
            }
        }
        ans += to_string(freq) + ch;
        return ans;
    }
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        return say(countAndSay(n-1));
    }
};