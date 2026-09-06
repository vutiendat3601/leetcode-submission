class Solution {
private:
    const int MAX = 5000;
    int n;
    int dfs(int k, int c, vector<vector<int>>& cache) {
        if (k > n)
            return MAX;
        if (k == n)
            return 0;
        if (cache[k][c] < 0) {
            if (c)
                return min(1 + dfs(k + c, c, cache), 2 + dfs(k + k, k, cache));
            return 2 + dfs(k + k, k, cache);
        }
        return cache[k][c];
    }

public:
    int minSteps(int n) {
        this->n = n;
        vector<vector<int>> cache(n, vector<int>(n, -1));
        return dfs(1, 0, cache);
    }
};