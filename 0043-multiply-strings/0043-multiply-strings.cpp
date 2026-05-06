class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        vector<int> cur_ans(m + n, 0);

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int x = (num1[i] - '0') * (num2[j] - '0'),
                    sum = cur_ans[i + j + 1] + x;
                cur_ans[i + j + 1] = sum % 10, cur_ans[i + j] += sum / 10;
            }
        }

        string ans = "";
        int i = 0;
        while (i < m + n && cur_ans[i] == 0)
            i++;
        while (i < m + n)
            ans += to_string(cur_ans[i]), i++;

        return ans.empty() ? "0" : ans;
    }
};