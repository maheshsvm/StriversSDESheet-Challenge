class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = INT_MIN;
        stack<int> st;
        vector<int> nsr(n) , nsl(n);

        // nearest smaller to right
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && heights[i] <= heights[st.top()] ) st.pop();
            nsr[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        while( !st.empty() ) st.pop();

        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[i] <= heights[st.top()] ) st.pop();
            nsl[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        for(int i = 0; i < n; i++){
            int area = heights[i] * (nsr[i] - nsl[i] - 1);
            maxArea = max(area , maxArea);
        }
        
        return maxArea;
    }
};