class Solution {
private:
    const int MOD = 1e9 + 7;
    int zero, one;
    int dfs(int n, unordered_map<int, int>& cache) {
        if (!n)
            return 1;
        if (!cache.count(n)) {
            cache[n] = 0;
            if (n - zero >= 0)
                cache[n] += dfs(n - zero, cache), cache[n] %= MOD;
            if (n - one >= 0)
                cache[n] += dfs(n - one, cache), cache[n] %= MOD;
        }
        return cache[n];
    }

public:
    int countGoodStrings(int low, int high, int zero, int one) {
        this->zero = zero, this->one = one;
        unordered_map<int, int> cache;
        int ans = 0;
        for (int i = high; i >= low; i--)
            ans += dfs(i, cache), ans %= MOD;

        return ans;
    }
};