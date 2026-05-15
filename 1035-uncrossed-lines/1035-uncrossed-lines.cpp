class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int r = 1; r <= m; r++)
            for (int c = 1; c <= n; c++) {
                int d = nums1[r - 1] == nums2[c - 1] ? 1 : 0;
                dp[r][c] =
                    max(max(dp[r - 1][c], dp[r][c - 1]), dp[r - 1][c - 1] + d);
            }
        return dp[m][n];
    }
};

// DP, time: O(m.n), space: O(m.n)