class Solution {
private:
    void solve(int row , int n , vector<int> &up, vector<int> &left , vector<int> &right , vector<string> &board , vector<vector<string>> &ans){
        if(row == n){
            ans.push_back(board);
            return;
        }

        for(int col = 0; col < n; col++){
            if(up[col] == 0 && right[col + row] == 0 && left[n + (col - row) - 1] == 0){
                board[row][col] = 'Q';
                up[col] = 1;
                right[col + row] = 1;
                left[n + (col - row) - 1] = 1;
                solve(row + 1 , n , up , left , right , board , ans);
                // backtracking
                board[row][col] = '.';
                up[col] = 0;
                right[col + row] = 0;
                left[n + (col - row) - 1] = 0;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {

        vector<int> up(n , 0);
        vector<int> left(2*n - 1  , 0);
        vector<int> right(2*n - 1 , 0);
        string s(n , '.');
        vector<string> board(n , s);
        vector<vector<string>> ans;
        solve(0 , n , up , left , right , board , ans);
        return ans;
    }
};