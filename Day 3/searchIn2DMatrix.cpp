class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int low = 0 , high = m*n-1;
        int mid;

        while(low <= high){
            mid = low + (high - low)/2;

            int row = mid/n;
            int col = mid%n;

            if(matrix[row][col] == target) return true;
            else if(matrix[row][col] < target) low = mid + 1;
            else high = mid - 1;
        }

        return false;
    }
};