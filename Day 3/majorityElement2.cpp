class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        int cnt1 = 0 , cnt2 = 0 , elm1 , elm2;

        for(int i = 0; i < n; i++){
            if(cnt1 == 0 && nums[i] != elm2){
                elm1 = nums[i]; cnt1 = 1;
            }
            else if(cnt2 == 0 && nums[i] != elm1){
                elm2 = nums[i]; cnt2 = 1;
            }
            else if(elm1 == nums[i]) cnt1++;
            else if(elm2 == nums[i]) cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = 0 , cnt2 = 0;
        int len = n/3;

        for(int i = 0; i < n; i++){
            if(nums[i] == elm1) cnt1++;
            else if(nums[i] == elm2) cnt2++;
        }

        if(cnt1 > len) ans.push_back(elm1);
        if(cnt2 > len) ans.push_back(elm2);
        return ans;
    }
};