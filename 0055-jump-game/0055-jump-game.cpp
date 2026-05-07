class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (n < 2)
            return 1;

        vector<int> dp(n);
        dp[0] = nums[0];
        for (int i = 1; i < n - 1; i++) {
            if (dp[i - 1] < i)
                return 0;
            dp[i] = i + nums[i] > dp[i - 1] ? i + nums[i] : dp[i - 1];
        }
        return dp[n - 2] >= n - 1;
    }
};

// DP, time: O(n), space: O(n)