class Solution {
private:
/*
    int n;
    int dfs(int k, int isSell, vector<int>& prices,
            vector<vector<int>>& cache) {
        if (k >= n)
            return 0;
        if (cache[k][isSell] < 0) {
            cache[k][isSell] = dfs(k + 1, isSell, prices, cache);
            if (isSell)
                cache[k][isSell] = max(
                    cache[k][isSell], prices[k] + dfs(k + 2, 0, prices, cache));
            else
                cache[k][isSell] =
                    max(cache[k][isSell],
                        -prices[k] + dfs(k + 1, 1, prices, cache));
        }
        return cache[k][isSell];
    }
*/
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));
        for (int k = n - 1; k >= 0; k--) {
            for (int isSell = 0; isSell <= 1; isSell++) {
                dp[k][isSell] = dp[k + 1][isSell];
                if (isSell)
                    dp[k][isSell] = max(dp[k][isSell], prices[k] + dp[k + 2][0]);
                else
                    dp[k][isSell] = max(dp[k][isSell], -prices[k] + dp[k + 1][1]);
            }
        }
        return dp[0][0];
    }
};