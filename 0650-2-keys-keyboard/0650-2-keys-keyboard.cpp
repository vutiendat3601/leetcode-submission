class Solution {
private:
    const int MAX = 5000;

public:
    int minSteps(int n) {
        vector<int> dp(n + 1, 0);
        for (int i = 2; i <= n; i++) {
            dp[i] = MAX;
            for (int j = 1; j < i; j++) {
                if (!(i % j))
                    dp[i] = min(dp[i], dp[j] + i / j);
            }
        }
        return dp[n];
    }
};