class Solution {
private:
    int n;
    int dfs(vector<int>& nums, int k, vector<int>& cache) {
        if (k >= n)
            return 0;
        if (!cache[k]) {
            cache[k] = 1;
            for (int i = k + 1; i < n; i++)
                if (nums[i] > nums[k])
                    cache[k] = max(cache[k], 1 + dfs(nums, i, cache));
        }

        return cache[k];
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        vector<int> cache(n, 0);
        int ans = 0;
        for (int i = 0; i < n; i++)
            ans = max(ans, dfs(nums, i, cache));
        return ans;
    }
};

// DFS + Memorization, time: O(n), space: O(n)