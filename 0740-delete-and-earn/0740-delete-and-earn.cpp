class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size(), MX = 10000;
        vector<int> points(MX + 1, 0);
        for (auto& num : nums)
            points[num] += num;
        vector<int> dp(MX + 1, 0);
        for (int i = 0; i <= MX; i++)
            dp[i] = points[i];
        for (int i = 2; i <= MX; i++)
            dp[i] = max(dp[i - 1], points[i] + dp[i - 2]);
        return dp[MX];
    }
};