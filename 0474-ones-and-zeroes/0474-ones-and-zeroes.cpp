class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (auto& str : strs) {
            vector<int> cnt(2, 0);
            for (auto& c : str)
                cnt[c - '0']++;
            for (int z = m; z >= cnt[0]; z--)
                for (int o = n; o >= cnt[1]; o--)
                    dp[z][o] = max(dp[z][o], 1 + dp[z - cnt[0]][o - cnt[1]]);
        }
        return dp[m][n];
    }
};