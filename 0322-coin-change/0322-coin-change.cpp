class Solution {
private:
    int MAX = 100000;

public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, MAX);
        dp[0] = 0;
        for (int a = 1; a <= amount; a++) {
            for (auto& coin : coins)
                if (a >= coin)
                    dp[a] = min(dp[a], 1 + dp[a - coin]);
        }
        return dp[amount] < MAX ? dp[amount] : -1;
    }
};