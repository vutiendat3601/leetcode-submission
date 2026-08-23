class Solution {
private:
    int n, target;
    int dfs(int k, int sum, vector<int>& nums,
            vector<unordered_map<int, int>>& cache) {
        if (k >= n)
            return sum == target ? 1 : 0;
        if (!cache[k].count(sum))
            cache[k][sum] = dfs(k + 1, sum + nums[k], nums, cache) +
                            dfs(k + 1, sum - nums[k], nums, cache);
        return cache[k][sum];
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size(), this->target = target;
        vector<unordered_map<int, int>> cache(n);
        return dfs(0, 0, nums, cache);
    }
};