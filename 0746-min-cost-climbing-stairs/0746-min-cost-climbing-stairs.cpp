class Solution {
private:
    int dfs(int k, vector<int>& cost, vector<int>& cache) {
        if (!k || k == 1)
            return 0;
        if (cache[k] < 0)
            cache[k] = min(cost[k - 2] + dfs(k - 2, cost, cache),
                           cost[k - 1] + dfs(k - 1, cost, cache));
        return cache[k];
    }

public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> cache(n + 1, -1);
        return dfs(n, cost, cache);
    }
};