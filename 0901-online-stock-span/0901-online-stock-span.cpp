class StockSpanner {
private:
    stack<int> st;
    unordered_map<int, int> cnt;

public:
    StockSpanner() {}

    int next(int price) {
        int ans = 1;
        while (st.size() && st.top() <= price)
            ans += cnt[st.top()], st.pop();

        cnt[price] = ans;
        st.push(price);
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */