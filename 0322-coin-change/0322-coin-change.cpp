class Solution {
private:
    int MAX = 100000;
    int dfs(int amount, vector<int>& coins, vector<int>& cache) {
        if (!amount)
            return 0;
        if (cache[amount] < 0) {
            cache[amount] = MAX;
            for (auto& coin : coins)
                if (amount >= coin)
                    cache[amount] = min(cache[amount],
                                        1 + dfs(amount - coin, coins, cache));
        }
        return cache[amount];
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> cache(amount + 1, -1);
        int ans = dfs(amount, coins, cache);
        return ans < MAX ? ans : -1;
    }
};