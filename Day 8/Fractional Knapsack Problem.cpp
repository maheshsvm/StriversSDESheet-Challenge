/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        vector<pair<double,int>> profitWeightRatio;
        double ans = 0;
        
        for(int i = 0; i < n; i++){
            double ratio = (double)arr[i].value / arr[i].weight;
            profitWeightRatio.push_back({ratio , i});
        }
        
        sort(profitWeightRatio.begin() , profitWeightRatio.end(), greater<pair<double,int>>());
        
        for(int i = 0; i < n; i++){
            int srcIdx = profitWeightRatio[i].second;
            if(W >= arr[srcIdx].weight){
                W -= arr[srcIdx].weight;
                ans += arr[srcIdx].value;
            }
            else{
                ans += (double)arr[srcIdx].value * W / arr[srcIdx].weight;
                break;
            }
        }
        
        return ans;
    }
        
};