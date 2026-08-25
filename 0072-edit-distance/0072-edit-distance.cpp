class Solution {
    /*
    private:
        int n1, n2;
        int dfs(int k, int i, string& w1, string& w2, vector<vector<int>>&
    cache) { if (k >= n1) return n2 - i; if (i >= n2) return n1 - k; if
    (cache[k][i] == INT_MAX) { if (w1[k] == w2[i]) { cache[k][i] = dfs(k + 1, i
    + 1, w1, w2, cache); } else { int insert = 1 + dfs(k, i + 1, w1, w2, cache);
                    int remove = 1 + dfs(k + 1, i, w1, w2, cache);
                    int replace = 1 + dfs(k + 1, i + 1, w1, w2, cache);
                    cache[k][i] = min(insert, min(remove, replace));
                }
            }
            return cache[k][i];
        }
    */
public:
    int minDistance(string w1, string w2) {
        int n1 = w1.size(), n2 = w2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        for (int i = n1; i >= 0; i--)
            dp[i][n2] = n1 - i;
        for (int j = n2; j >= 0; j--)
            dp[n1][j] = n2 - j;
        for (int i = n1 - 1; i >= 0; i--) {
            for (int j = n2 - 1; j >= 0; j--) {
                if (w1[i] == w2[j])
                    dp[i][j] = dp[i + 1][j + 1];
                else
                    dp[i][j] = 1 + min(dp[i + 1][j + 1],
                                       min(dp[i + 1][j], dp[i][j + 1]));
            }
        }

        return dp[0][0];
    }
};