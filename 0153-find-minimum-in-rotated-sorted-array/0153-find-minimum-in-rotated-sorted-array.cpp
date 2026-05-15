class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size(), l = 0, r = n - 1, ans = nums[0];
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] >= nums[0]) {
                l = mid + 1;
            } else {
                ans = nums[mid];
                r = mid - 1;
            }
        }
        return ans;
    }
};

// Binary Search, time: O(log(n))