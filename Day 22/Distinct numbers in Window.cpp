vector<int> Solution::dNums(vector<int> &A, int B) {
    int n = A.size();
    vector<int> ans;
    if(B > n) return ans;
    unordered_map<int , int> mp;
    int i = 0, j = 0;
    while(j < n){
        mp[A[j]]++;
        if(j - i + 1 == B){
            ans.push_back(mp.size());
            mp[A[i]]--;
            if(mp[A[i]] <= 0) mp.erase(A[i]);
            i++;
        }
        j++;
    }
    return ans;
}
