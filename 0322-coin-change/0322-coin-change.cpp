class Solution {
private:
    int dfs(vector<int>& coins, int amount, unordered_map<int, int>& cache) {
        if (!amount)
            return 0;
        if (!cache.count(amount)) {
            cache[amount] = INT_MAX;
            for (auto& c : coins)
                if (amount >= c) {
                    int cur_ans = dfs(coins, amount - c, cache);
                    if (cur_ans < INT_MAX)
                        cache[amount] = min(cache[amount], 1 + cur_ans);
                }
        }
        return cache[amount];
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        unordered_map<int, int> cache;
        int ans = dfs(coins, amount, cache);
        return ans < INT_MAX ? ans : -1;
    }
};