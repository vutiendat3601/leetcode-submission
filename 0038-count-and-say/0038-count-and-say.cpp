class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        for (int i = 2; i <= n; i++) {
            int j = 0;
            string tmp = "";
            while (j < ans.size()) {
                char c = ans[j];
                int cnt = 0;
                while (ans[j] == c)
                    cnt++, j++;

                tmp += to_string(cnt) + c;
            }

            ans = tmp;
        }
        return ans;
    }
};