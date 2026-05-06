class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (auto& c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else {
                if (!st.size()) {
                    return 0;
                }
                if ((c == ')' && st.top() == '(') ||
                    (c == ']' && st.top() == '[') ||
                    (c == '}' && st.top() == '{')) {
                    st.pop();
                } else {
                    return 0;
                }
            }
        }
        return st.empty();
    }
};

// Stack, time: O(n), space: O(n)