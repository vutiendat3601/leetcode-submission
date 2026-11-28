class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1), pref(n, 1), suff(n, 1);
        pref[0] = nums[0], suff[n - 1] = nums[n - 1];
        for (int i = 1; i < n; i++) {
            pref[i] = nums[i] * pref[i - 1];
            suff[n - 1 - i] = nums[n - 1 - i] * suff[n - i];
        }
        ans[0] = suff[1], ans[n - 1] = pref[n - 2];
        for (int i = 1; i < n - 1; i++)
            ans[i] = pref[i - 1] * suff[i + 1];

        return ans;
    }
};