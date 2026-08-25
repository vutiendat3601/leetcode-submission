class Solution {
private:
    int n;
    int dfs(int a, int clipboard, unordered_map<string, int>& cache) {
        if (a == n)
            return 0;
        if (a > n)
            return INT_MAX / 2;
        string key = to_string(a) + "_" + to_string(clipboard);
        if (!cache.count(key)) {

            cache[key] = 2 + dfs(a + a, a, cache);
            if (clipboard)
                cache[key] =
                    min(cache[key], 1 + dfs(a + clipboard, clipboard, cache));
        }
        return cache[key];
    }

public:
    int minSteps(int n) {
        this->n = n;
        unordered_map<string, int> cache;
        return dfs(1, 0, cache);
    }
};