class Solution {
private:
    int dfs(vector<int>& days, vector<int>& costs, int k,
            unordered_map<int, int>& cache) {
        if (k < 0)
            return 0;
        if (!cache.count(k)) {
            cache[k] = INT_MAX;
            vector<int> prev_days = {days[k] - 1, days[k] - 7, days[k] - 30};
            for (int i = 0; i < 3; i++) {
                int j = k;
                while (j >= 0 && days[j] > prev_days[i])
                    j--;
                cache[k] = min(cache[k], costs[i] + dfs(days, costs, j, cache));
            }
        }
        return cache[k];
    }

public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        unordered_map<int, int> cache;
        return dfs(days, costs, n - 1, cache);
    }
};

// DFS + Memorization, time: O(n), space: O(n)