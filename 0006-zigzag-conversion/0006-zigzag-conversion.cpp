class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        if (n <= numRows || numRows <= 1)
            return s;

        string ans(n, '\0');
        int idx = 0, step = 2 * numRows - 2;

        // First row
        for (int i = 0; i < n; i += step)
            ans[idx++] = s[i];

        // Row [2, n - 2]
        for (int i = 1; i < numRows - 1; i++) {
            int j = i + step;
            ans[idx++] = s[i];
            while (j < n)
                ans[idx++] = s[j - 2 * i], ans[idx++] = s[j], j += step;
            if (j - 2 * i < n)
                ans[idx++] = s[j - 2 * i];
        }

        // Last row
        for (int i = numRows - 1; i < n; i += step)
            ans[idx++] = s[i];

        return ans;
    }
};