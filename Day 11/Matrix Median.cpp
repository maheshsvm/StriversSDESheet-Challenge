int countLesserThanEqualToMid(vector<int>& arr , int mid){
        int l = 0 , h = arr.size() - 1;
        int md;
        while(l <= h){
            md = (l + h) >> 1;
            if(arr[md] <= mid){
                l = md + 1;
            }
            else{
                h = md - 1;
            }
        }
        return l;
    }

    int median(vector<vector<int>> &matrix, int R, int C){
        // code here     
        int low = 1 , high = 1e9;
        int mid , cnt;
        while(low <= high){
            mid = (low + high) >> 1;
            cnt = 0;
            for(int i= 0; i < R; i++){
                cnt += countLesserThanEqualToMid(matrix[i] , mid);
            }
            
            if(cnt <= (R * C) >> 1){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return low;
    }
    
int Solution::findMedian(vector<vector<int> > &A) {
    return median(A , A.size() , A[0].size());
}

