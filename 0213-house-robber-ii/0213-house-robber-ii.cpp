class Solution {
private:
    int dfs(int k, int n, vector<int>& nums, vector<int>& cache) {
        if (k >= n)
            return 0;
        if (cache[k] < 0)
            cache[k] = max(nums[k] + dfs(k + 2, n, nums, cache),
                           dfs(k + 1, n, nums, cache));
        return cache[k];
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        vector<int> cache1(n, -1), cache2(n, -1);
        return max(dfs(0, n - 1, nums, cache1), dfs(1, n, nums, cache2));
    }
};