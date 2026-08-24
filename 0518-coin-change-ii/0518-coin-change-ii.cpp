typedef unsigned long long ull;
class Solution {
private:
/*
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
*/
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<ull>> dp(n + 1, vector<ull>(amount + 1, 0));
        for (int k = 0; k <= n; k++)
            dp[k][0] = 1;
        for (int k = n - 1; k >= 0; k--) {
            for (int a = 1; a <= amount; a++) {
                dp[k][a] = dp[k + 1][a];
                if (a >= coins[k])
                    dp[k][a] += dp[k][a - coins[k]];
            }
        }
        return dp[0][amount];
    }
};