class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size(), l = 0, r = n - 1, idx = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] > target) {
                r = mid - 1;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                idx = mid;
                break;
            }
        }
        if (idx != -1) {
            l = r = idx;
            while (l > 0 && nums[l - 1] == target)
                l--;
            while (r < n - 1 && nums[r + 1] == target)
                r++;
            return {l, r};
        }
        return {-1, -1};
    }
};

// Binary Search, time: O(log(n)), space: O(1)