class Solution {
private:
    bool isPossible(char target , int row , int col, vector<vector<char>>& board){
        // checking for row
        for(int j = 0; j < 9; j++){
            if(board[row][j] == target){
                return false;
            }
        }

        // checking for col
        for(int i = 0; i < 9; i++){
            if(board[i][col] == target){
                return false;
            }
        }

        //cheking for 3x3 matrix
        int startRow = row <= 2? 0 : (row <= 5?3:6);
        int startCol = col <= 2? 0 : (col <= 5?3:6);
        int endRow = startRow + 2;
        int endCol = startCol + 2;

        for(int i = startRow; i <= endRow; i++){
            for(int j = startCol; j <= endCol; j++){
                if(board[i][j] == target){
                    return false;
                }
            }
        }

        return true;
    }

    bool solve(vector<vector<char>>& board , int row , int col){
        //base case
        if(row == 9 && col == 9){
            return true;
        }
        for(char i = '1'; i <= '9'; i++){
            if(isPossible(i , row , col , board)){
                board[row][col] = i;

                // finding next empty cell
                int newRow = row , newCol = 0;
                for(newRow = row; newRow < 9; newRow++){
                    for(newCol = 0; newCol < 9; newCol++){
                        if(board[newRow][newCol] == '.'){
                            break;
                        }
                    }
                    if(newCol != 9){
                        break;
                    }
                }
                
                // calling to fill next empty cells
                bool flag = solve(board , newRow , newCol);
                if(flag == true){
                    return true;
                }

                // backtracking
                board[row][col] = '.';
            }
        }

        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        int row , col;

        // finding out the first empty cell
        for( row = 0; row < 9; row++){
            for(col = 0; col < 9; col++){
                if(board[row][col] == '.'){
                    break;
                }
            }
            if(col != 9){
                break;
            }
        }
        solve(board , row , col);
    }
};