class Solution {
private:
    int dfs(int m, int n, vector<vector<int>>& cache) {
        if (!m || !n)
            return 1;
        if (!cache[m][n]) {
            if (m)
                cache[m][n] += dfs(m - 1, n, cache);
            if (n)
                cache[m][n] += dfs(m, n - 1, cache);
        }
        return cache[m][n];
    }

public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> cache(m, vector<int>(n, 0));
        return dfs(m - 1, n - 1, cache);
    }
};