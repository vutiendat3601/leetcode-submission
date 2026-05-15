class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0] ? 0 : 1;
        for (int r = 0; r < m; r++)
            for (int c = 0; c < n; c++) {
                if (!grid[r][c]) {
                    bool rb = r - 1 >= 0, cb = c - 1 >= 0;
                    if (rb && cb)
                        dp[r][c] = dp[r - 1][c] + dp[r][c - 1];
                    else if (rb)
                        dp[r][c] = dp[r - 1][c];
                    else if (cb)
                        dp[r][c] = dp[r][c - 1];
                }
            }
        return dp[m - 1][n - 1];
    }
};

// DP, time: O(m.n), space: O(m.n)