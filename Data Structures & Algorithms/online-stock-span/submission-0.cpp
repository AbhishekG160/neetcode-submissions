class StockSpanner {
    stack<pair<int, int>> st;
    // val , span
public:
    StockSpanner() {}
    int next(int price) {
        // if curr val more than top --> consumes the span of the top elem (acts as a wall for any other element coming)
        // else push the val with span 1
        int span = 1;
        while(!st.empty() && price >= st.top().first){
            span += st.top().second;
            st.pop();    
        }
        st.push({price , span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */