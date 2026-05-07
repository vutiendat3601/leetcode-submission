class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int l = 0, t = 0, r = n - 1, b = n - 1, i = 0, j = 0;
        bool row = 1, lr = 1, td = 0;

        while (i++ <= n * n) {
            int val = i;
            if (row) {
                // left to right
                if (lr && j <= r) {
                    ans[t][j++] = val;
                    if (j > r)
                        t++, j = t, td = 1, row = 0;
                }
                // right to left
                else if (!lr && j >= l) {
                    ans[b][j--] = val;
                    if (j < l)
                        b--, j = b, td = 0, row = 0;
                }
            } else {
                // top to down
                if (td && j <= b) {
                    ans[j++][r] = val;
                    if (j > b)
                        r--, j = r, lr = 0, row = 1;
                }
                // down to top
                else if (!td && j >= t) {
                    ans[j--][l] = val;
                    if (j < t)
                        l++, j = l, lr = 1, row = 1;
                }
            }
        }
        return ans;
    }
};