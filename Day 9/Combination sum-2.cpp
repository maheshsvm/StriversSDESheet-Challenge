class Solution {
private:
    void solve(vector<int>& candidates, int idx , int target , vector<int> & ds , vector<vector<int>> &ans){
        if(target == 0){
            ans.push_back(ds);
            return;
        }
        for(int i = idx; i < candidates.size(); i++){
            if(candidates[i] > target) return;
            if(i > idx && candidates[i] == candidates[i-1]) continue;
            ds.push_back(candidates[i]);
            solve(candidates , i+1 , target - candidates[i] , ds , ans);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin() , candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        solve(candidates , 0 , target , ds , ans);
        return ans;
    }
};