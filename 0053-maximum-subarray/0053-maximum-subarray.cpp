class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), sum = 0, ans = INT_MIN, pref_sum = 0;
        for (int i = 0; i < n; i++) {
            pref_sum = max(pref_sum + nums[i], nums[i]);
            ans = max(ans, pref_sum);
        }
        return ans;
    }
};

// DP, time: O(n), space: O(1)