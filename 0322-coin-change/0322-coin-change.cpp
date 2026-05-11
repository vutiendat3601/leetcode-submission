class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int MX = 1e4 + 1;
        vector<int> dp(amount + 1, MX);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++)
            for (auto& coin : coins)
                if (i - coin >= 0)
                    dp[i] = min(dp[i], dp[i - coin] + 1);

        return dp[amount] < MX ? dp[amount] : -1;
    }
};