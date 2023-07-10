class Solution {
private:
    bool isPresentInRightArray(vector<int>& nums , int mid){
        return ((mid % 2 == 0 && nums[mid + 1] == nums[mid]) || (mid%2 != 0 && nums[mid - 1] == nums[mid]));
    }
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 0 , high = n - 1;
        int mid;
        while(low < high){
            mid = low + (high - low )/2;
            if(isPresentInRightArray( nums ,  mid)){
                low = mid + 1;
            }
            else{
                high = mid;
            }
        }
        return nums[low];
    }
};