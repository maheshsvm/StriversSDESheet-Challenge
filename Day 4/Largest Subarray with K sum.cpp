class Solution{
    public:
    int maxLen(vector<int>&a, int n)
    {   long long k = 0;
        int longest = 0;
        int i = 0 , j = 0;
        long long sum = 0;
        while(j < n){
            sum += a[j];
            
            while(sum > k){
                if(sum == k) longest = max(longest , j - i + 1);
                sum -= a[i];
                i++;
            }
    
            if(sum == k) longest = max(longest , j - i + 1);
            j++;
        }
        return longest;
    }
};