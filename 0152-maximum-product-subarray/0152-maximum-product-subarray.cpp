class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), mn = 1, mx = 1, ans = nums[0];
        for (auto& num : nums) {
            int p = num * mx, pmn = mn * num;
            mx = max(max(p, num), pmn);
            mn = min(min(p, num), pmn);
            ans = max(ans, mx);
        }
        return ans;
    }
};