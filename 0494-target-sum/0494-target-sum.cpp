class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size(), sum = accumulate(nums.begin(), nums.end(), 0);
        unordered_map<int, int> dp;
        dp[0] = 1;
        for (int r = 0; r < n; r++) {
            unordered_map<int, int> nxt;
            for (auto [key, val] : dp)
                nxt[key + nums[r]] += val, nxt[key - nums[r]] += val;
            dp = nxt;
        }

        return dp[target];
    }
};

// DP, time: O(n.m), space: O(n.m)