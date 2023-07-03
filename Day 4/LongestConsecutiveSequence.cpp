class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> us;
        int cnt = 0 , longest = 0;

        for(int val : nums) us.insert(val);

        for(int element : us){
            cnt = 0;
            if(us.find(element - 1) == us.end()){
                cnt = 1;
                while(us.find(element + 1) != us.end()){
                    cnt++;
                    element++;
                }
            }
            longest = max(longest , cnt);
        }
        return longest;
    }
};