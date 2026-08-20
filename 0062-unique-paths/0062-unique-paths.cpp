class Solution {
private:
    int dfs(int r, int c, vector<vector<int>>& cache) {
        if (!r || !c)
            return 1;
        if (cache[r][c] < 0) {
            cache[r][c] = 0;
            if (r)
                cache[r][c] += dfs(r - 1, c, cache);
            if (c)
                cache[r][c] += dfs(r, c - 1, cache);
        }
        return cache[r][c];
    }

public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> cache(m, vector<int>(n, -1));
        return dfs(m - 1, n - 1, cache);
    }
};
