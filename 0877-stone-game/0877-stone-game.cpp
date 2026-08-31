class Solution {
    /*
    private:
        int dfs(int l, int r, vector<int>& piles, vector<vector<int>>& cache) {
            if (l > r)
                return 0;
            if (cache[l][r] < 0) {
                int takeLeft = piles[l], takeRight = piles[r];
                if ((r - l + 1) & 1)
                    takeLeft = takeRight = 0;
                cache[l][r] = max(takeLeft + dfs(l + 1, r, piles, cache),
                                  takeRight + dfs(l, r - 1, piles, cache));
            }
            return cache[l][r];
        }
    */
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        int sum = accumulate(piles.begin(), piles.end(), 0);
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int l = n - 1; l >= 0; l--) {
            for (int r = l; r < n; r++) {
                int takeLeft = piles[l], takeRight = piles[r];
                if ((r - l + 1) & 1)
                    takeLeft = takeRight = 0;
                if (l == r)
                    dp[l][r] = takeLeft;
                else
                    dp[l][r] =
                        max(takeLeft + dp[l + 1][r], takeRight + dp[l][r - 1]);
            }
        }
        return dp[0][n - 1] > sum / 2;
    }
};