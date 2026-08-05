class Solution {
private:
    int dfs(int amount, int k, vector<int>& coins, vector<vector<int>>& cache) {
        if (!amount)
            return 1;
        if (cache[k][amount] < 0) {
            cache[k][amount] = 0;
            int z = k;
            while (z >= 0) {
                if (amount >= coins[z])
                    cache[k][amount] += dfs(amount - coins[z], z, coins, cache);
                z--;
            }
        }
        return cache[k][amount];
    }

public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> cache(n, vector<int>(amount + 1, -1));
        sort(coins.rbegin(), coins.rend());
        return dfs(amount, n - 1, coins, cache);
    }
};