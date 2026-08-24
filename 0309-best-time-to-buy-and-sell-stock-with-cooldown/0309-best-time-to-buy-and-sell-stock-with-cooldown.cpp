class Solution {
private:
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

public:
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        vector<vector<int>> cache(n, vector<int>(2, -1));
        return dfs(0, 0, prices, cache);
    }
};