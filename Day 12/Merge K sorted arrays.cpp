#include <bits/stdc++.h> 
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // intitial configuration
    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
    vector<int> indexProcessed(k , 0);
    vector<int> ans;
    for(int i = 0; i < k; i++){
        pq.push({kArrays[i][0] , i});
    }

    while(!pq.empty()){
        int val = pq.top().first;
        int arrayNumber = pq.top().second;
        ans.push_back(val);
        pq.pop();

        if(indexProcessed[arrayNumber] < kArrays[arrayNumber].size() - 1){
            indexProcessed[arrayNumber]++;
            pq.push({kArrays[arrayNumber][indexProcessed[arrayNumber]] , arrayNumber});
        }
    }

    return ans;
    
}
