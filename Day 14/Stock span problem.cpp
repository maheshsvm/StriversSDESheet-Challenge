class StockSpanner {
    stack<pair<int,int>> st;
public:
    StockSpanner() {
    }
    
    int next(int price) {
        int currentSpan = 1;
        while(!st.empty() && st.top().first <= price){
            currentSpan += st.top().second;
            st.pop();
        }
        st.push({price , currentSpan});
        return currentSpan;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */