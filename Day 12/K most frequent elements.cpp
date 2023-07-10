typedef pair<int , int> pii;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int , int> mp;
        priority_queue<pii , vector<pii> , greater<pii>> pq;
        vector<int> ans;

        for(int a : nums) mp[a]++;

        for(auto p : mp){
            pq.push({p.second , p.first});
            if(pq.size() > k) pq.pop();
        }

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};