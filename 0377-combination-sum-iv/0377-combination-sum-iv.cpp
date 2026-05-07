class Solution {
private:
    int dfs(vector<int>& nums, int target, unordered_map<int, int>& cache) {
        if (!target)
            return 1;
        if (!cache.count(target)) {
            cache[target] = 0;
            for (auto& num : nums)
                if (target - num >= 0)
                    cache[target] += dfs(nums, target - num, cache);
        }
        return cache[target];
    }

public:
    int combinationSum4(vector<int>& nums, int target) {
        unordered_map<int, int> cache;
        return dfs(nums, target, cache);
    }
};

// DFS + Memorization, time: O(n), space: O(n)