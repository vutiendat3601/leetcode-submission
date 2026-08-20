class Solution {
private:
    int dfs(int r, int c, vector<vector<int>>& grid,
            vector<vector<int>>& cache) {
        if (!r && !c)
            return grid[r][c] ? 0 : 1;
        if (cache[r][c] < 0) {
            cache[r][c] = 0;
            if (!grid[r][c]) {
                if (r)
                    cache[r][c] += dfs(r - 1, c, grid, cache);
                if (c)
                    cache[r][c] += dfs(r, c - 1, grid, cache);
            }
        }
        return cache[r][c];
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> cache(m, vector<int>(n, -1));
        return dfs(m - 1, n - 1, grid, cache);
    }
};