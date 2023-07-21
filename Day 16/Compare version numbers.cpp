class Solution {
public:
    int compareVersion(string version1, string version2) {
        int m = version1.size();
        int n = version2.size();
        int iv1 = 0 , jv1 = 0 , iv2 = 0  , jv2 = 0;
        while(iv1 < m || iv2 < n){
            jv1 = iv1;
            jv2 = iv2;
            while(jv1 < m && version1[jv1] != '.') jv1++;
            while(jv2 < n && version2[jv2] != '.') jv2++;
            int num1 = 0 , num2 = 0;
            if(iv1 < m)
                num1 = stoi(version1.substr(iv1 , jv1 - iv1));
            if(iv2 < n)
                num2 = stoi(version2.substr(iv2 , jv2 - iv2));
            if(num1 < num2) return -1;
            else if(num1 > num2) return 1;

            iv1 = jv1+1;
            iv2 = jv2+1;
        }
        return 0;
    }
};