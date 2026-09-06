class Solution {
private:
    const int MAX = 5000;
    int n;
    int dfs(int k, int c, vector<vector<int>>& cache) {
        if (k > n)
            return MAX;
        if (k == n)
            return 0;
        if (cache[k][c] < 0)
            cache[k][c] = min(c ? 1 + dfs(k + c, c, cache) : MAX,
                              2 + dfs(k + k, k, cache));

        return cache[k][c];
    }

public:
    int minSteps(int n) {
        this->n = n;
        vector<vector<int>> cache(n, vector<int>(n, -1));
        return dfs(1, 0, cache);
    }
};