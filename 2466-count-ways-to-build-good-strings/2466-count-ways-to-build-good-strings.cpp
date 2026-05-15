class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        int ans = 0, MOD = 1e9 + 7;
        vector<int> dp(high + 1, 0);
        dp[0] = 1;
        for (int i = 0; i <= high; i++) {
            if (i - zero >= 0)
                dp[i] += dp[i - zero], dp[i] %= MOD;
            if (i - one >= 0)
                dp[i] += dp[i - one], dp[i] %= MOD;
            if (low <= i)
                ans += dp[i], ans %= MOD;
        }

        return ans;
    }
};