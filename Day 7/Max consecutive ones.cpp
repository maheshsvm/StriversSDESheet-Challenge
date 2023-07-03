class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0 , pos = 0 , n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                ans = max(ans , i - pos);
                pos = i + 1;
            }
        }
        ans = max(ans , n - pos);
        return ans;
    }
};