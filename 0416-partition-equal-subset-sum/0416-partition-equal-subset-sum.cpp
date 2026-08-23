class Solution {
    /*
    private:
        int n;
        bool dfs(int k, int target, vector<int>& nums,
                 vector<unordered_map<int, bool>>& cache) {
            if (!target)
                return 1;
            if (k >= n)
                return 0;
            if (!cache[k].count(target)) {
                cache[k][target] = dfs(k + 1, target, nums, cache);
                if (!cache[k][target] && target >= nums[k])
                    cache[k][target] = dfs(k + 1, target - nums[k], nums, cache);
            }
            return cache[k][target];
        }
    */
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0), target = sum / 2;
        if (sum & 1)
            return 0;
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, 0));
        for (int k = 0; k < n; k++)
            dp[k][0] = 1;
        for (int t = 1; t <= target; t++) {
            for (int k = n - 1; k >= 0; k--) {
                dp[k][t] = dp[k + 1][t];
                if (!dp[k][t] && t >= nums[k])
                    dp[k][t] = dp[k + 1][t - nums[k]];
            }
        }

        return dp[0][target];
    }
};