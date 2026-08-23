class Solution {
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

public:
    bool canPartition(vector<int>& nums) {
        n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0), target = sum / 2;
        if (sum & 1)
            return 0;
        vector<unordered_map<int, bool>> cache(n);
        return dfs(0, target, nums, cache);
    }
};