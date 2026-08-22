class Solution {
private:
    int dfs(int amount, int k, vector<int>& coins, vector<vector<int>>& cache) {
        if (!amount)
            return 1;
        if (k < 0)
            return 0;
        int n = coins.size();
        if (cache[amount][k] < 0) {
            cache[amount][k] = 0;
            if (amount >= coins[k])
                cache[amount][k] += dfs(amount - coins[k], k, coins, cache);
            cache[amount][k] += dfs(amount, k - 1, coins, cache);
        }
        return cache[amount][k];
    }

public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        sort(coins.begin(), coins.end());
        vector<vector<int>> cache(amount + 1, vector<int>(n, -1));
        return dfs(amount, n - 1, coins, cache);
    }
};