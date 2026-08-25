class Solution {
    /*
    private:
        int n, n1, n2;
        string s, s1, s2;
        bool dfs(int i1, int i2, vector<vector<int>>& cache) {
            int k = i1 + i2;
            if (k >= n)
                return 1;
            if (i1 > n1 || i2 > n2)
                return 0;
            if (cache[i1][i2] < 0) {
                bool s1_cont = i1 < n1 ? s[k] == s1[i1] : 0;
                bool s2_cont = i2 < n2 ? s[k] == s2[i2] : 0;
                cache[i1][i2] = 0;
                if (s1_cont && s2_cont)
                    cache[i1][i2] =
                        dfs(i1 + 1, i2, cache) || dfs(i1, i2 + 1, cache);
                else if (s1_cont)
                    cache[i1][i2] = dfs(i1 + 1, i2, cache);
                else if (s2_cont)
                    cache[i1][i2] = dfs(i1, i2 + 1, cache);
            }
            return cache[i1][i2];
        }
    */
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s3.size(), n1 = s1.size(), n2 = s2.size();
        if (n1 + n2 != n)
            return 0;
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        dp[n1][n2] = 1;
        for (int i1 = n1; i1 >= 0; i1--) {
            for (int i2 = n2; i2 >= 0; i2--) {
                int k = i1 + i2;
                if (k >= n)
                    continue;
                bool s1_matched = s3[k] == s1[i1],
                     s2_matched = i2 < n2 ? s3[k] == s2[i2] : 0;
                if (s1_matched && s2_matched)
                    dp[i1][i2] = dp[i1 + 1][i2] || dp[i1][i2 + 1];
                else if (s1_matched)
                    dp[i1][i2] = dp[i1 + 1][i2];
                else if (s2_matched)
                    dp[i1][i2] = dp[i1][i2 + 1];
            }
        }
        return dp[0][0];
    }
};
