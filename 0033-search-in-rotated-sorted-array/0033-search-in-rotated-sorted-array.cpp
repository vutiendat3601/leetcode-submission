class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size(), l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] < nums[0]) {
                if (target > nums[n - 1] || target < nums[mid])
                    r = mid - 1;
                else
                    l = mid + 1;

            } else {
                if (target < nums[0] || target > nums[mid])
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }
        return -1;
    }
};

// Binary Search, time: O(log(n)), space: O(1)