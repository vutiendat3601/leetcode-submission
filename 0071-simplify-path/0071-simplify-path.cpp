class Solution {
public:
    string simplifyPath(string path) {
        path += "/";
        int n = path.size();
        stack<string> st;
        string cur = "", ans = "";
        for (char& ch : path) {
            if (ch == '/') {
                if (cur == "..") {
                    if (!st.empty()) {
                        st.pop();
                    }
                } else if (cur != "" && cur != ".") {
                    st.push(cur);
                }
                cur = "";
            } else {
                cur += ch;
            }
        }
        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
            if (!st.empty()) {
                ans = "/" + ans;
            }
        }
        ans = "/" + ans;
        return ans;
    }
};