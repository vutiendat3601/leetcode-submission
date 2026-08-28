class Solution {
private:
    const int MAX = 100000;
    int n;
    int dfs(int a, int clipboard, vector<vector<int>>& cache) {
        if (a == n)
            return 0;
        if (cache[a][clipboard] == INT_MAX) {
            cache[a][clipboard] = MAX;
            if (a + a <= n)
                cache[a][clipboard] =
                    min(cache[a][clipboard], 2 + dfs(a + a, a, cache));
            if (clipboard && a + clipboard <= n)
                cache[a][clipboard] =
                    min(cache[a][clipboard],
                        1 + dfs(a + clipboard, clipboard, cache));
        }
        return cache[a][clipboard];
    }

public:
    int minSteps(int n) {
        this->n = n;
        vector<vector<int>> cache(n + 1, vector<int>(n + 1, INT_MAX));
        return dfs(1, 0, cache);
    }
};