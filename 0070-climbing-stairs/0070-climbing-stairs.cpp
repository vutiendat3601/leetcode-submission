class Solution {
private:
    int dfs(int k, vector<int>& cache) {
        if (!k || k == 1)
            return 1;
        if (!cache[k])
            cache[k] = dfs(k - 1, cache) + dfs(k - 2, cache);
        return cache[k];
    }

public:
    int climbStairs(int n) {
        vector<int> cache(n + 1, 0);
        return dfs(n, cache);
    }
};