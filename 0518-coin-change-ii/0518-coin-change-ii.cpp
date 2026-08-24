class Solution {
private:
    int n;
    int dfs(int k, int amount, vector<int>& coins, vector<vector<int>>& cache) {
        if (!amount)
            return 1;
        if (k >= n)
            return 0;
        if (cache[k][amount] < 0) {
            cache[k][amount] = dfs(k + 1, amount, coins, cache);
            if (amount >= coins[k])
                cache[k][amount] += dfs(k, amount - coins[k], coins, cache);
        }
        return cache[k][amount];
    }

public:
    int change(int amount, vector<int>& coins) {
        n = coins.size();
        vector<vector<int>> cache(n, vector<int>(amount + 1, -1));
        return dfs(0, amount, coins, cache);
    }
};