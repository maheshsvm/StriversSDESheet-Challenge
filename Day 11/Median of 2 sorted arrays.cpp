class Solution {
private: 
    bool isEven(int a){
        return (a % 2 == 0);
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size() , n = nums2.size();
        if(m > n){
            return findMedianSortedArrays(nums2 , nums1);
        }
        int low = 0 , high = m;
        int cut1 , cut2 , l1 , l2 , r1 , r2;
        int lengthOfLeftHalf = (m + n + 1)/2;
        while(low <= high){

            cut1 = (low + high) >> 1;
            cut2 = lengthOfLeftHalf - cut1;

            l1 = cut1 > 0? nums1[cut1 - 1] : INT_MIN;
            l2 = cut2 > 0? nums2[cut2 - 1] : INT_MIN;

            r1 = cut1 < m? nums1[cut1] : INT_MAX;
            r2 = cut2 < n? nums2[cut2] : INT_MAX;

            if(l1 <= r2 && l2 <= r1){
                double median;
                if(isEven(m + n)){
                    median = ( max(l1 , l2) + min(r1 , r2))/2.0;
                
                }
                else{
                    median = max(l1 , l2);
                }
                return median;
            }

            if(l1 > r2){
                high = cut1 - 1;
            }
            else{
                low = cut1 + 1;
            }
        }

        return 0.0;
    }
};