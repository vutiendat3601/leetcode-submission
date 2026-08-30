class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size(), mni = 0, mxi = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            mni = nums[mni] < nums[i] ? mni : i;
            mxi = nums[mxi] > nums[i] ? mxi : i;
        }
        bool mnLeft = mni < n / 2, mxLeft = mxi < n / 2;

        if (mnLeft && mxLeft) {
            ans = max(mni + 1, mxi + 1);
        } else if (!mnLeft && !mxLeft) {
            ans = max(n - mni, n - mxi);
        } else {
            int tmp = mnLeft ? mni + 1 : n - mni;
            tmp += mxLeft ? mxi + 1 : n - mxi;
            ans = min(tmp, min(max(mni, mxi) + 1, n - min(mni, mxi)));
        }
        return ans;
    }
};