class StockSpanner {
    stack<pair<int,int>>st;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int stock=1;
        while(!st.empty() and st.top().first<=price){
            stock+=st.top().second;
            st.pop();
        }
        st.push({price,stock});
        return stock;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */