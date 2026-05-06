class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size(), l = 0, r = n - 1;
        vector<pair<int, int>> dups(n);
        for (int i = 0; i < n; i++)
            dups[i] = {nums[i], i};
        sort(dups.begin(), dups.end());
        while (l < r) {
            int sum = dups[l].first + dups[r].first;
            if (sum > target)
                r--;
            else if (sum < target)
                l++;
            else
                return {dups[l].second, dups[r].second};
        }
        return {};
    }
};

// Sorting + 2-pointers, time: O(n), space: O(1)