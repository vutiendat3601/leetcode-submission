class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            int cur_height = 0, cur_width = 0;
            for (int j = i; j < n; j++) {
                if (cur_width + books[j][0] > shelfWidth)
                    break;
                cur_width += books[j][0];
                cur_height = max(cur_height, books[j][1]);
                dp[i] = min(dp[i], cur_height + dp[j + 1]);
            }
        }
        return dp[0];
    }
};

// DP, time: O(n), space: O(n)