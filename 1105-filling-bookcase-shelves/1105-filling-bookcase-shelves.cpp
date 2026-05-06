class Solution {
private:
    int n, shelfWidth;

    int dfs(vector<vector<int>>& books, int k, unordered_map<int, int>& cache) {
        if (k >= n)
            return 0;
        if (!cache.count(k)) {
            cache[k] = INT_MAX;
            int curHeight = 0, curWidth = 0, i = k;
            while (i < n) {
                if (curWidth + books[i][0] > shelfWidth)
                    break;
                curHeight = max(curHeight, books[i][1]);
                curWidth += books[i][0];
                cache[k] = min(cache[k], curHeight + dfs(books, i + 1, cache));
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

// DFS, time: O(n), space: O(n)