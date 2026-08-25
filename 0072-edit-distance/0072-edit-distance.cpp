class Solution {
private:
    int n1, n2;
    int dfs(int k, int i, string& w1, string& w2, vector<vector<int>>& cache) {
        if (k >= n1)
            return n2 - i;
        if (i >= n2)
            return n1 - k;
        if (cache[k][i] == INT_MAX) {
            int match = 0;
            cache[k][i] = min(1 + dfs(k + 1, i, w1, w2, cache),
                              1 + (match = dfs(k + 1, i + 1, w1, w2, cache)));
            cache[k][i] = min(cache[k][i], 1 + dfs(k, i + 1, w1, w2, cache));
            if (w1[k] == w2[i])
                cache[k][i] = min(cache[k][i], match);
        }
        return cache[k][i];
    }

public:
    int minDistance(string w1, string w2) {
        n1 = w1.size(), n2 = w2.size();
        vector<vector<int>> cache(n1, vector<int>(n2, INT_MAX));
        return dfs(0, 0, w1, w2, cache);
    }
};