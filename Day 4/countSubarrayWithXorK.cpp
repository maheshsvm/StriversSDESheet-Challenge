int Solution::solve(vector<int> &A, int B) {
    unordered_map<int , int> um;
    int n = A.size();
    int preXor = 0 , count = 0;
    for(int i = 0; i < n; i++){
        preXor ^= A[i];
        if(preXor == B){
            count++;
        }
        int requiredXor = preXor^B;
        if(um.find(requiredXor) != um.end()){
            count += um[requiredXor];
        }
        
        um[preXor]++;
        
    }
    
    return count;
}
