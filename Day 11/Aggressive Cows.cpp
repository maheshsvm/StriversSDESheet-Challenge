bool isPossible(vector<int> &arr, int k,int n ,int mid){
    int cows = 1;
    int lastPlace = arr[0];
    for(int i = 0;i < n;i++){
        if(arr[i]-lastPlace >= mid){
  			cows++;
            if(cows == k){
                return true;
            }
            lastPlace = arr[i];
        }
    }
    return false;
}
int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    sort(stalls.begin(),stalls.end());
    int s = 0;
    int n = stalls.size();
    int maxi = 21222323,mini = -212212121;
    for(int i = 0;i < n;i++){
        maxi = max(stalls[i],maxi);
        mini = min(stalls[i],mini);
    }
    int e = maxi - mini;
    int mid = s + (e-s)/2;
    int ans  = -1;
    while(s <= e){
        if(isPossible(stalls,k,n,mid)){
            ans = mid;
            s = mid+1;
        }
        else{
            e = mid -1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}