class MinStack {
private:
    int index = -1;
    int capacity;
    vector<long> data;
    vector<long> mns;

public:
    MinStack() {
        capacity = 3 * 1E4 + 1;
        data.assign(capacity, LONG_MIN), mns.assign(capacity, LONG_MAX);
    }

    void push(int val) {
        index++, data[index] = val;
        if (index)
            mns[index] = min(mns[index - 1], data[index]);
        else
            mns[index] = data[index];
    }

    void pop() { mns[index] = LONG_MAX, data[index] = LONG_MIN, index--; }

    int top() { return data[index]; }

    int getMin() { return mns[index]; }
};
