class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size(), l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                return 1;
            }
            if (nums[mid] > nums[0]) { // The nums[mid] is in the 1st part
                if (target < nums[0] || target > nums[mid]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            } else if (nums[mid] < nums[0]) { // The nums[mid] is in the 2st part
                if (target > nums[n - 1] || target < nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else { // nums[mid] == nums[0], need to decide which part to continue with
                int k = mid - 1;
                while (k >= l && nums[k] == nums[0]) {
                    k--;
                }
                if (k < l) {
                    l = mid + 1;
                } else {
                    r = k;
                }
            }
        }
        return 0;
    }
};

// Binary Search, time: O(n), space: O(1)