class Solution {
private:
    int shelfWidth, n;

    int dfs(vector<vector<int>>& books, int k, unordered_map<int, int>& cache) {
        if (k >= n)
            return 0;
        if (!cache.count(k)) {
            int cur_width = 0, mx_height = 0, i = k;
            cache[k] = INT_MAX;
            while (i < n && cur_width + books[i][0] <= shelfWidth) {
                cur_width += books[i][0],
                    mx_height = max(mx_height, books[i][1]);
                cache[k] = min(cache[k], mx_height + dfs(books, i + 1, cache));
                i++;
            }
        }
        return cache[k];
    }

public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        n = books.size(), this->shelfWidth = shelfWidth;
        unordered_map<int, int> cache;
        return dfs(books, 0, cache);
    }
};

// DFS + Memorization, time: O(n), space: O(n)