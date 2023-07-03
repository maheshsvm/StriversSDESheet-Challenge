class Solution
{
private:
    void solve(int idx , int sum , vector<int>&arr , vector<int>&ans){
        ans.push_back(sum);
        for(int i = idx; i < nums.size(); i++){
            if(i > idx && nums[i] == nums[i-1]) continue;
            ds.push_back(nums[i]);
            solve(i+1 , nums , ds , ans);
            ds.pop_back();
        }
    }
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> ans;
        solve(0 , 0 , arr , ans);
        return ans;
    }
};