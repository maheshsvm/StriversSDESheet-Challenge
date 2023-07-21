class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for(int query : nums1){
            int i = 0;
            while(query != nums2[i]){
                i++;
            }

            for(; i < nums2.size(); i++){
                if(nums2[i] > query){
                    ans.push_back(nums2[i]);
                    break;
                }
            }
            if(i == nums2.size()){
                ans.push_back(-1);
            }
        }

        return ans;
    }
};

// cyclic case
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> ans(n);
        for(int i = 2*n - 1; i >= 0; i--){
            while(!st.empty() && nums[i%n] >= st.top()) st.pop();

            ans[i%n] = st.empty() ? -1 : st.top();
            st.push(nums[i%n]);
        }

        return ans;
    }
};