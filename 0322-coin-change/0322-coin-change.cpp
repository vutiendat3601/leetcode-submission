class Solution {
private:
    const int MAX = 100000;
    int dfs(int a, vector<int>& coins, vector<int>& cache) {
        if (a <= 0)
            return 0;
        if (cache[a] < 0) {
            cache[a] = MAX;
            for (auto& c : coins)
                if (a - c >= 0)
                    cache[a] = min(cache[a], 1 + dfs(a - c, coins, cache));
        }
        return cache[a];
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> cache(amount + 1, -1);
        int ans = dfs(amount, coins, cache);
        return ans < MAX ? ans : -1;
    }
};