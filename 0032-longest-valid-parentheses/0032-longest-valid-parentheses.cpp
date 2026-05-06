class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        vector<int> dp(n, 0);
        stack<int> st;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                if (st.size()) {
                    int idx = st.top();
                    st.pop();
                    dp[i] += dp[i - 1] + 1;
                    if (idx > 0)
                        dp[i] += dp[idx - 1];
                    ans = max(ans, dp[i]);
                }
            }
        }
        return ans * 2;
    }
};