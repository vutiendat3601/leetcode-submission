class Solution {
private:
    int dfs(int amount, int k, vector<int>& coins, vector<vector<int>>& cache) {
        if (!amount)
            return 1;
        int n = coins.size();
        if (cache[amount][k] < 0) {
            cache[amount][k] = 0;
            for (int i = 0; i < n; i++) {
                if (amount >= coins[i] && (k >= n ? 1 : coins[i] <= coins[k]))
                    cache[amount][k] += dfs(amount - coins[i], i, coins, cache);
            }
        }
        return cache[amount][k];
    }

public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> cache(amount + 1, vector<int>(n + 1, -1));
        return dfs(amount, n, coins, cache);
    }
};