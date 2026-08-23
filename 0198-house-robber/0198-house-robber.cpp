class Solution {
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

public:
    int rob(vector<int>& nums) {
        n = nums.size();
        unordered_map<int, int> cache;
        return dfs(0, nums, cache);
    }
};