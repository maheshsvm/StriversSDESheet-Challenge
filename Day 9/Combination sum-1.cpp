class Solution {
private:
    void solve(int i , int sum , vector<int>& candidates, int target , vector<vector<int>>& ans , vector<int>&ds){
        if(sum == target){ ans.push_back(ds); return;}
        if(i == candidates.size()){
            if(sum == target) ans.push_back(ds);
            return;
        }

        // pick
        if(target >= (candidates[i] + sum)){

            ds.push_back(candidates[i]);
            solve(i , sum+candidates[i] , candidates , target , ans , ds);
            ds.pop_back();
        }

        // not pick
        solve(i+1 , sum , candidates , target , ans , ds);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ansSet;
        vector<int> ds;
        solve(0 , 0 , candidates , target , ansSet , ds);
        // vector<vector<int>> ans(ansSet.begin() , ansSet.end());
        return ansSet;
    }
};