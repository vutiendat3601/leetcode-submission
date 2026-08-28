class Solution {
private:
    int dfs(int n, vector<int>& cache) {
        if (!n || n == 1)
            return 1;
        if (cache[n] < 0)
            cache[n] = dfs(n - 1, cache) + dfs(n - 2, cache);
        return cache[n];
    }

public:
    int climbStairs(int n) {
        vector<int> cache(n + 1, -1);
        return dfs(n, cache);
    }
};