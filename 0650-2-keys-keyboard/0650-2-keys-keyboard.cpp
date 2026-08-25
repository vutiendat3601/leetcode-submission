class Solution {
    /*
    private:
        int n;
        int dfs(int a, int clipboard, vector<vector<int>>& cache) {
            if (a == n)
                return 0;
            if (a > n)
                return INT_MAX / 2;
            string key = to_string(a) + "_" + to_string(clipboard);
            if (cache[a][clipboard] == INT_MAX) {
                cache[a][clipboard] = 2 + dfs(a + a, a, cache);
                if (clipboard)
                    cache[a][clipboard] =
                        min(cache[a][clipboard],
                            1 + dfs(a + clipboard, clipboard, cache));
            }
            return cache[a][clipboard];
        }
    */
public:
    int minSteps(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX / 2));
        int ans = INT_MAX;
        dp[1][0] = 0;
        for (int a = 1; a <= n; a++) {
            for (int clipboard = 0; clipboard <= a; clipboard++) {
                dp[a][clipboard] =
                    min(dp[a][clipboard], 1 + dp[a - clipboard][clipboard]);
                dp[a][a] = min(dp[a][a], dp[a][clipboard] + 1);
                if (a == n)
                    ans = min(ans, min(dp[a][clipboard], dp[a][a]));
            }
        }
        return ans;
    }
};