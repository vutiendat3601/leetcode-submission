class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n = boxGrid.size(), m = boxGrid[0].size();
        vector<vector<char>> ans(m, vector<char>(n, '.'));
        int i = n - 1, j = 0;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                ans[r][c] = boxGrid[i--][j];
                if (i < 0)
                    j++, i = n - 1;
            }
        }

        for (int c = 0; c < n; c++) {
            i = m;
            for (int r = m - 1; r >= 0; r--) {
                if (ans[r][c] == '#')
                    ans[r][c] = '.', i--, ans[i][c] = '#';
                else if (ans[r][c] == '*')
                    i = r;
            }
        }
        return ans;
    }
};