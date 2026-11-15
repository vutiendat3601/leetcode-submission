class MinStack {
private:
    int index = -1;
    int capacity;
    vector<int> data;
    stack<int> st;

public:
    MinStack() {
        capacity = 3 * 1E4 + 1;
        data.assign(capacity, INT_MIN);
    }

    void push(int val) {
        index++, data[index] = val;
        if (st.size())
            st.push(min(st.top(), data[index]));
        else
            st.push(data[index]);
    }

    void pop() { st.pop(), data[index] = LONG_MIN, index--; }

    int top() { return data[index]; }

    int getMin() { return st.top(); }
};
