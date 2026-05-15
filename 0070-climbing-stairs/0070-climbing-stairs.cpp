class Solution {
private:
    int dfs(int n, vector<int>& cache) {
        if (n <= 1)
            return 1;
        if (!cache[n])
            cache[n] = dfs(n - 1, cache) + dfs(n - 2, cache);
        return cache[n];
    }

public:
    int climbStairs(int n) {
        vector<int> cache(n + 1, 0);
        return dfs(n, cache);
    }
};