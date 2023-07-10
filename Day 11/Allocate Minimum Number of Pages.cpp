//User function template in C++

class Solution 
{
    private:
    bool canAllocate(int arr[] , int n , int m , long long maxPages){
        long long allocatedPages = arr[0];
        int studentCount = 1;
        if(allocatedPages > maxPages){
            return false;
        }
        
        for(int i = 1; i < n; i++){
            if(allocatedPages + arr[i] <= maxPages){
                allocatedPages += arr[i];
            }
            else{
                studentCount++;
                allocatedPages = arr[i];
                if(studentCount > m){
                    return false;
                }
            }
        }
        return true;
    }
    public:
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        //code here
        if(N < M){
            return -1;
        }
        long long low = *max_element(A , A + N);
        long long high = accumulate(A , A + N , 0);
        long long mid;
        int result = -1;
        while(low <= high){
            mid = (low + high) >> 1;
            if(canAllocate(A , N , M , mid)){
                result = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return result;
    }
};