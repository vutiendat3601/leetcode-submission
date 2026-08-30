class Solution {
private:
    int dfs(int st, int en, vector<int>& piles, vector<vector<int>>& cache) {
        if (st > en)
            return 0;
        if (cache[st][en] < 0) {
            // Alice takes piles[st], Bob takes piles[en]
            cache[st][en] = piles[st] + dfs(st + 1, en - 1, piles, cache);
            // Alice takes piles[en], Bob takes piles[st]
            cache[st][en] =
                max(cache[st][en], piles[en] + dfs(st + 1, en - 1, piles, cache));
            // Alice takes piles[st], Bob takes piles[st + 1]
            cache[st][en] =
                max(cache[st][en], piles[st] + dfs(st + 2, en, piles, cache));
            // Alice takes piles[en], Bob takes piles[en - 1]
            cache[st][en] =
                max(cache[st][en], piles[en] + dfs(st, en - 2, piles, cache));
        }
        return cache[st][en];
    }

public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size(), sum = accumulate(piles.begin(), piles.end(), 0);
        vector<vector<int>> cache(n, vector<int>(n, -1));
        int alice = dfs(0, n - 1, piles, cache);
        return alice > sum / 2;
    }
};