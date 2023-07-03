class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        int maxToLeft = height[0];
        vector<int> maxToRight(n);
        maxToRight[n - 1] = height[n - 1];

        for(int i = n - 2; i >= 0; i--){
            maxToRight[i] = max(height[i] , maxToRight[i + 1]);
        }

        for(int i = 0; i < n; i++){
            maxToLeft = max(maxToLeft , height[i]);
            ans += min(maxToLeft , maxToRight[i]) - height[i];
        }

        return ans;

    }
};