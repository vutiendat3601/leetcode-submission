class Solution {
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

public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        int sum = accumulate(piles.begin(), piles.end(), 0);
        vector<vector<int>> cache(n, vector<int>(n + 1, -1));
        return dfs(0, n - 1, piles, cache) > sum / 2;
    }
};