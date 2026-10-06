class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        for (auto c : s) {
            if (c == '(' || st.empty() || st.top() == ')')
                st.push(c);
            else
                st.pop();
        }
        return st.size();
    }
};

// Stack, time: O(n), space: O(n)