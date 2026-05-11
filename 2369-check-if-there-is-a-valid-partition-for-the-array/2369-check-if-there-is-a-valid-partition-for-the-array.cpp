class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n + 1, 0);
        dp[n] = 1;
        for (int i = n - 2; i >= 0; i--) {
            if (i + 3 <= n && dp[i + 3])
                dp[i] =
                    (nums[i] == nums[i + 1] && nums[i] == nums[i + 2]) ||
                    (nums[i] + 1 == nums[i + 1] && nums[i] + 2 == nums[i + 2]);
            if (dp[i + 2])
                dp[i] = dp[i] || nums[i] == nums[i + 1];
        }
        return dp[0];
    }
};