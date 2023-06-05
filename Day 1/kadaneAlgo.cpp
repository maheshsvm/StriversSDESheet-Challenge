#include <bits/stdc++.h> 
long long maxSubarraySum(int nums[], int n)
{
    /*
        Don't write main().
        Don't read input, it is passed as function argument.    
        No need to print anything.
        Taking input and printing output is handled automatically.
    */
    long long ans = INT_MIN;
    long long sum = 0;
    for(int i = 0; i < n; i++){
        sum += nums[i];
        if(sum < 0){
            sum = 0;
        }
        ans = max(sum , ans);
    }
    return ans;
}