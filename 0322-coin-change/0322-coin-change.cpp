class Solution {
private:
    int dfs(int amount, vector<int>& coins, vector<int>& cache) {
        if (!amount)
            return 0;
        if (cache[amount] == INT_MAX) {
            bool available = 0;
            for (auto& coin : coins) {
                if (amount >= coin) {
                    int ans = dfs(amount - coin, coins, cache);
                    if (ans != -1)
                        available = 1, cache[amount] = min(cache[amount], 1 + ans);
                }
            }
            if (!available)
                cache[amount] = -1;
        }
        return cache[amount];
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> cache(amount + 1, INT_MAX);
        return dfs(amount, coins, cache);
    }
};