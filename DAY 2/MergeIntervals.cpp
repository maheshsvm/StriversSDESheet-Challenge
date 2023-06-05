#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    int n = intervals.size();
    vector<vector<int>> ans;

    sort(intervals.begin() , intervals.end());

    ans.push_back(intervals[0]);

    for(int i = 1; i < n; i++){
        vector<int> firstInterval = ans[ans.size() - 1];
        vector<int> &secondInterval = intervals[i];
        if(secondInterval[0] <= firstInterval[1]){
            ans.pop_back();
            ans.push_back({min(firstInterval[0] , secondInterval[0]) , max(firstInterval[1] , secondInterval[1])});
        }
        else{
            ans.push_back(secondInterval);
        }
    }

    return ans;
}
