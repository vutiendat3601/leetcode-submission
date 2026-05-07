class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = books[i][1] + dp[i + 1];
            int j = i + 1, curWidth = books[i][0], curHeight = books[i][1];
            while (j < n && curWidth + books[j][0] <= shelfWidth) {
                curWidth += books[j][0],
                    curHeight = max(curHeight, books[j][1]);
                dp[i] = min(dp[i], curHeight + dp[j + 1]);
                j++;
            }
        }
        return dp[0];
    }
};

// DP, time: O(n), space: O(n)