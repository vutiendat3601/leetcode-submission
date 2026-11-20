class Solution {
public:
    int countGoodTriplets(vector<int>& nums, int a, int b, int c) {
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                int abs1 = abs(nums[i] - nums[j]);
                for (int k = j + 1; k < n; k++) {
                    int abs2 = abs(nums[j] - nums[k]);
                    int abs3 = abs(nums[i] - nums[k]);
                    if (abs1 <= a && abs2 <= b && abs3 <= c)
                        ans++;
                }
            }
        }
        return ans;
    }
};