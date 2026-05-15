class Solution {
private:
    int dfs(int i, int j, int m, int n, vector<vector<int>>& cache) {
        if (i >= m || j >= n)
            return 0;
        if (i == m - 1 && j == n - 1)
            return 1;
        if (!cache[i][j])
            cache[i][j] =
                dfs(i + 1, j, m, n, cache) + dfs(i, j + 1, m, n, cache);
        return cache[i][j];
    }

public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> cache(m, vector<int>(n, 0));
        return dfs(0, 0, m, n, cache);
    }
};

// DP + memorization, time: O(m.n), space: O(m.n)