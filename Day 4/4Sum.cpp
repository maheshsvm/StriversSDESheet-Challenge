class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin() , nums.end());

        for(int start = 0; start < n; start++){
            if(start > 0 && nums[start] == nums[start - 1]) continue;
            int ThreeSumTarget = target - nums[start];

            // using 3 sum to get other 3 numbers
            for(int i = start + 1; i < n; i++){
                if(i > (start + 1) && nums[i] == nums[i-1]) continue;
                int j = i + 1; 
                int k = n - 1;
                while(j < k){
                    long long  sum = (long long)nums[i] + nums[j] + nums[k];
                    if(sum < ThreeSumTarget) j++;
                    else if(sum > ThreeSumTarget) k--;
                    else{
                        ans.push_back({nums[start] , nums[i] , nums[j] , nums[k]});
                        j++ , k--;
                        while(j < k && nums[j] == nums[j-1]) j++;
                        while(j < k && nums[k] == nums[k+1]) k--;
                    }
                }
            }
        }

        return ans;
    }
};