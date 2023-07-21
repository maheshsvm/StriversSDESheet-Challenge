class Solution {
public:
    int myAtoi(string s) {
    int n = s.length();

    bool neg=false;

    string  ans ="";

    for(int i=0; i<n; i++){

        if(s[i]=='-')neg=true;

        if(s[i]<65 && s[i]!='-'){

            ans = ans+s[i];

        }

    }

    //cout<<ans;

    if(neg==true)return -stoi(ans);

    return stoi(ans);
    }
};