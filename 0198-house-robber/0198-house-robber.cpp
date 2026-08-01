class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        vector<int> dp(n + 1, 0);
        dp[1] = nums[0];
        for (int k = 2; k <= n; k++)
            dp[k] = max(nums[k - 1] + dp[k - 2], dp[k - 1]);

        return dp[n];
    }
};