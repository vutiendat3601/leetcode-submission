class Solution {
private:
    int dfs(vector<vector<int>>& grid, int m, int n,
            vector<vector<int>>& cache) {
        if (!m && !n)
            return 1;
        if (cache[m][n] < 0) {
            cache[m][n] = 0;
            if (m && !grid[m - 1][n])
                cache[m][n] += dfs(grid, m - 1, n, cache);
            if (n && !grid[m][n - 1])
                cache[m][n] += dfs(grid, m, n - 1, cache);
        }
        return cache[m][n];
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> cache(m, vector<int>(n, -1));
        return grid[0][0] || grid[m - 1][n - 1] ? 0 : dfs(grid, m - 1, n - 1, cache);
    }
};