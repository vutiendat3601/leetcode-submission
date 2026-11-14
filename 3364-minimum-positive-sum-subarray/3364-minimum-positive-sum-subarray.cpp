class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size(), left = 0, right = 0, ans = INT_MAX;
        for (int x = l; x <= r; x++) {
            int k = 0, sum = 0;
            while (k < x)
                sum += nums[k], k++;

            if (sum > 0)
                ans = min(ans, sum);
            for (int i = 0; i + x < n; i++) {
                sum -= nums[i];
                sum += nums[i + x];
                if (sum > 0)
                    ans = min(ans, sum);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};