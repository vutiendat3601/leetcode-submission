class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size(), longest = 0, ans = 0;
        vector<int> dp(n, 1), cnt(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    if (1 + dp[j] > dp[i]) {
                        dp[i] = 1 + dp[j];
                        cnt[i] = cnt[j];
                    } else if (1 + dp[j] == dp[i]) {
                        cnt[i] += cnt[j];
                    }
                }
            }
            longest = max(longest, dp[i]);
        }
        for (int i = 0; i < n; i++) {
            if (dp[i] == longest)
                ans += cnt[i];
        }
        return ans;
    }
};