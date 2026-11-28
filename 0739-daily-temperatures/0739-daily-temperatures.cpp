class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n);
        stack<int> st;
        st.push(0);
        for (int i = 1; i < n; i++) {
            int k = 0;
            while (st.size() && temperatures[i] > temperatures[st.top()]) {
                k = st.top(), st.pop();
                ans[k] = i - k;
            }
            st.push(i);
        }
        return ans;
    }
};