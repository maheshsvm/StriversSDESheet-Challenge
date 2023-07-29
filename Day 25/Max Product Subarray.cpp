class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // either prefix or suffix max sum
        int prefix = 1;
        int maxi = INT_MIN;
        bool hasZero = false;

        for(auto num : nums){
            if(num == 0){
                hasZero = true;
                prefix = 1;
                continue;
            }
            prefix *= num;
            maxi = max(maxi , prefix);
        }

        int suffix = 1;
        for(int i = nums.size() - 1; i >= 0; i--){
            if(nums[i] == 0){
                hasZero = true;
                suffix = 1;
                continue;
            }
            suffix *= nums[i];
            maxi = max(maxi , suffix);
        }
        if(hasZero) return max(maxi , 0);
        return maxi;
    }
};