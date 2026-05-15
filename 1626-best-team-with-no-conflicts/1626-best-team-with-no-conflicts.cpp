class Solution {
private:
    int n;
    int dfs(vector<pair<int, int>>& sorted, int k,
            unordered_map<int, int>& cache) {
        if (k > n)
            return 0;

        if (!cache.count(k)) {
            cache[k] = 0;
            auto& [mn_age, mn_score] = sorted[k];
            for (int i = k + 1; i <= n; i++) {
                auto& [age, score] = sorted[i];
                if (age >= mn_age && score >= mn_score)
                    cache[k] = max(cache[k], score + dfs(sorted, i, cache));
            }
        }
        return cache[k];
    }

public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        n = scores.size();
        vector<pair<int, int>> sorted;
        sorted.push_back({INT_MIN, INT_MIN});
        for (int i = 0; i < n; i++)
            sorted.push_back({ages[i], scores[i]});
        sort(sorted.begin(), sorted.end());
        unordered_map<int, int> cache;
        return dfs(sorted, 0, cache);
    }
};