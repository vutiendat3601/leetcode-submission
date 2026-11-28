class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        int n = s.size();
        string ans = "", tmp = "", aux = "", numStr = "";
        for (int i = n - 1; i >= 0; i--) {
            if ('0' <= s[i] && s[i] <= '9') {
                numStr = string(1, s[i]) + numStr;
            } else {
                if (numStr.size()) {
                    int k = stoi(numStr);
                    aux = st.top();
                    for (int j = 0; j < k - 1; j++)
                        st.push(aux);
                    numStr = "";
                }
                if (s[i] == '[') {
                    tmp = "";
                    while (st.top() != "]")
                        tmp += st.top(), st.pop();
                    st.pop(), st.push(tmp);
                } else {
                    st.push(string(1, s[i]));
                }
            }
        }
        if (numStr.size()) {
            int k = stoi(numStr);
            aux = st.top();
            for (int j = 0; j < k - 1; j++)
                st.push(aux);
            numStr = "";
        }
        while (st.size())
            ans += st.top(), st.pop();
        return ans;
    }
};