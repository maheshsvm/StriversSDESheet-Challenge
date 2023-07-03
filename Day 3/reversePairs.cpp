class Solution {
private:
    int merge(vector<int> &nums , int low , int mid , int high){
        int count = 0;
        int *a = new int[mid - low + 1];
        int *b = new int[high - mid];
        int aidx = 0 , bidx = 0;
        for(int i = low; i <=mid; i++){
            a[aidx++] = nums[i];
        }
        for(int i = mid + 1; i <= high; i++){
            b[bidx++] = nums[i];
        }
        int leftArraySize = aidx , rightArraySize = bidx;
        int leftArrayPointer = 0 , rightArrayPointer = 0 , arrPointer = low;
        int j = 0;

        // counting reverse pairs
        for(int i = 0; i < leftArraySize; i++){
            while(j < rightArraySize && (a[i] > 2LL * b[j]) ) j++;
            count += j;
            
        }

        while(leftArrayPointer < leftArraySize && rightArrayPointer < rightArraySize){
            if(a[leftArrayPointer] <= b[rightArrayPointer]){
                nums[arrPointer++] = a[leftArrayPointer++];
            }
            else{
                // if(a[leftArrayPointer] > 2*b[rightArrayPointer]){
                //     count += (leftArraySize - leftArrayPointer);
                // }
                nums[arrPointer++] = b[rightArrayPointer++];
            }
        }

        while(leftArrayPointer < leftArraySize){
            nums[arrPointer++] = a[leftArrayPointer++];
        }
        while(rightArrayPointer < rightArraySize){
            nums[arrPointer++] = b[rightArrayPointer++];
        }
        delete[] a;
        delete[] b;
        return count;
    }
    int mergeSort(vector<int> &nums , int low , int high){
        int count = 0;
        int mid = low + (high - low)/2;
        if(low < high){
            count += mergeSort(nums, low , mid);
            count += mergeSort(nums , mid+1 , high);
            count += merge(nums, low , mid , high);
        }
        
        return count;
    }
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums , 0 , nums.size() - 1);
    }
};