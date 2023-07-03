class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int i = 0 , j = 0;
        int ans = 0;
        unordered_map<char , int> st;

        while(j < n){
            if(st.find(s[j]) != st.end() && st[s[j]] >= i){
                i = st[s[j]] + 1;
            }
            st[s[j]] = j;
            ans = max(ans , j - i + 1);
            j++;
        }

        return ans;
    }
};