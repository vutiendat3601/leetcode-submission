class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n);
        stack<int> st;
        st.push(0);
        for (int i = 1; i < n; i++) {
            while (st.size() && temperatures[i] > temperatures[st.top()])
                ans[st.top()] = i - st.top(), st.pop();
            st.push(i);
        }
        return ans;
    }
};