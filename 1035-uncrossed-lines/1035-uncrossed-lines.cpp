class Solution {
private:
    int m, n;
    int dfs(vector<int>& nums1, vector<int>& nums2, int i, int j,
            unordered_map<string, int>& cache) {
        if (i >= m)
            return 0;
        string key = to_string(i) + "," + to_string(j);
        if (!cache.count(key)) {
            cache[key] = dfs(nums1, nums2, i + 1, j, cache);
            for (int k = j; k < n; k++)
                if (nums2[k] == nums1[i])
                    cache[key] = max(
                        cache[key], 1 + dfs(nums1, nums2, i + 1, k + 1, cache));
        }
        return cache[key];
    }

public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        m = nums1.size(), n = nums2.size();
        unordered_map<string, int> cache;
        return dfs(nums1, nums2, 0, 0, cache);
    }
};

// Brute Force, time: O(m^n), space: O(m^n)