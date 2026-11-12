class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size(), l = 0, r = 1, ans = 1;
        bool isUp = 1;
        while (r < n) {
            if (nums[r] > nums[r - 1]) {
                if (nums[r] <= nums[l] || !isUp)
                    l = r - 1, isUp = !isUp;

            } else if (nums[r] < nums[r - 1]) {
                if (nums[r] >= nums[l] || isUp)
                    l = r - 1, isUp = !isUp;
            } else {
                l = r;
            }
            ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};