class Solution {
private:
    int dfs(int k, vector<int>& nums, vector<int>& cache) {
        int n = nums.size();
        if (k >= n)
            return 0;
        if (cache[k] < 0)
            cache[k] =
                max(nums[k] + dfs(k + 2, nums, cache), dfs(k + 1, nums, cache));
        return cache[k];
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> cache(n, -1);
        return dfs(0, nums, cache);
    }
};