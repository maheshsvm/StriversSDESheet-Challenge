class Solution {
private:
    int combination(int m , int n){
        double res = 1;
        for(int i = 1; i <= n; i++){
            res = res * (m - n + i) / i;
        }
        return (int)res;
    }
public:
    int uniquePaths(int m, int n) {
        int steps = m + n - 2;
        int mini = min(m , n);
        return combination(steps , mini - 1);
    }
};