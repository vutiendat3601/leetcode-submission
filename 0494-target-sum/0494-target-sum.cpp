class Solution {
private:
    int n;
    int dfs(int k, int sum, vector<int>& nums,
            vector<unordered_map<int, int>>& cache) {
        if (k >= n)
            return sum ? 0 : 1;
        if (!cache[k].count(sum))
            cache[k][sum] = dfs(k + 1, sum + nums[k], nums, cache) +
                            dfs(k + 1, sum - nums[k], nums, cache);
        return cache[k][sum];
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size();
        vector<unordered_map<int, int>> cache(n);
        return dfs(0, target, nums, cache);
    }
};