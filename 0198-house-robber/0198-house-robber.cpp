class Solution {
/*
private:
    int n;
    int dfs(int k, vector<int>& nums, unordered_map<int, int>& cache) {
        if (k >= n)
            return 0;
        if (!cache.count(k))
            cache[k] =
                max(nums[k] + dfs(k + 2, nums, cache), dfs(k + 1, nums, cache));
        return cache[k];
    }
*/

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, 0);
        dp[n - 1] = nums[n - 1];
        for (int k = n - 2; k >= 0; k--)
            dp[k] = max(nums[k] + dp[k + 2], dp[k + 1]);
        return dp[0];
    }
};