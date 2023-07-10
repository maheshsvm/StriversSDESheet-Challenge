class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        if(n > m){
            return kthElement(arr2 , arr1 , m , n , k);
        }
        int low = max(0 , k - m);
        int high = min(n , k);
        while(low <= high){
            int cut1 = (low + high)>>1;
            int cut2 = k - cut1;
            
            int l1 = cut1 > 0? arr1[cut1 - 1]:INT_MIN;
            int r1 = cut1 < n? arr1[cut1] : INT_MAX;
            
            int l2 = cut2 > 0? arr2[cut2 - 1]:INT_MIN;
            int r2 = cut2 < m? arr2[cut2] : INT_MAX;
            
            if(l1 <= r2 && l2 <= r1){
                return max(l1 , l2);
            }   
            
            if(l1 > r2){
                high = cut1 - 1;
            }
            else{
                low = cut1 + 1;
            }
        }
        return 0;
    }
};