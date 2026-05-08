class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), ans = 0, INF = 1E9;
        vector<int> dp(n + 1, INF);
        dp[0] = -INF;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= n; j++)
                if (dp[j - 1] < nums[i] && nums[i] < dp[j])
                    dp[j] = nums[i];
        }
        for (int i = 1; i <= n; i++)
            if (dp[i] < INF)
                ans = i;
        return ans;
    }
};