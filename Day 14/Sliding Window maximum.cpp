class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        list<int> lst;
        int i = 0 , j = 0;
        int n = nums.size();
        while(j < n){
            while(!lst.empty() && lst.back() < nums[j]){
                lst.pop_back();
            }
            lst.push_back(nums[j]);
            if(j - i + 1 == k){
                ans.push_back(lst.front());
                if(lst.front() == nums[i]){
                    lst.pop_front();
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};