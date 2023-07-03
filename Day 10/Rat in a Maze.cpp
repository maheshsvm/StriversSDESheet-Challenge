class Solution{
    private:
    bool isValid(int row , int col , int n){
        return row >= 0 && row < n && col >= 0 && col < n;
    }
    void solve(int row , int col , vector<vector<int>> &m, int n , string& ds , vector<string>&ans){
        if(row == n-1 && col == n-1){
            ans.push_back(ds);
            return;
        }
        
        // down
        if(isValid(row + 1 , col , n) && m[row+1][col] == 1){
            ds.push_back('D');
            m[row][col] = 0;
            solve(row+1 , col , m , n , ds , ans);
            m[row][col] = 1;
            ds.pop_back();
            
        }
        //right
        if(isValid(row , col+1 , n) && m[row][col+1] == 1){
            ds.push_back('R');
            m[row][col] = 0;
            solve(row , col+1 , m , n , ds , ans);
            m[row][col] = 1;
            ds.pop_back();
            
        }
        //up
        if(isValid(row - 1 , col , n) && m[row-1][col] == 1){
            ds.push_back('U');
            m[row][col] = 0;
            solve(row-1 , col , m , n , ds , ans);
            m[row][col] = 1;
            ds.pop_back();
            
        }
        //left
        if(isValid(row , col - 1 , n) && m[row][col-1] == 1){
            ds.push_back('L');
            m[row][col] = 0;
            solve(row , col-1 , m , n , ds , ans);
            m[row][col] = 1;
            ds.pop_back();
            
        }
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        string ds;
        if(m[0][0] == 0) return ans;
        solve(0 , 0 , m , n , ds , ans);
        return ans;
    }
};