class Solution {
public:
    bool isAnagram(string str1, string str2) {
        unordered_map<char , int> m1 , m2;
        for(char ch : str1) m1[ch]++;
        for(char ch : str2) m2[ch]++;
        return m1 == m2;
    }
};