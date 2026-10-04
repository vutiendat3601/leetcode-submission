class MinStack {
private:
    int idx = -1;
    int sz = 0;
    vector<int> mn, st;

public:
    MinStack() {
        mn.assign(50000, INT_MAX);
        st.resize(50000);
    }

    void push(int value) {
        idx++;
        mn[idx] = min(idx - 1 >= 0 ? mn[idx - 1] : INT_MAX, value);
        st[idx] = value;
    }

    void pop() {
        mn[idx] = INT_MAX;
        idx--;
    }

    int top() { return st[idx]; }

    int getMin() { return mn[idx]; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */