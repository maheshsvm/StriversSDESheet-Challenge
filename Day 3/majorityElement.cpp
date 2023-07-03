class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int element = 0 , cnt = 0;

        for(int i = 0; i < n; i++){
            if(cnt == 0){
                element = nums[i]; cnt = 1;
            }
            else if(element == nums[i]) cnt++;
            else cnt--;
        }
        return element;
    }
};