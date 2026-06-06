class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ans = 0, n = nums.size(), j = 0, last = INT_MIN, cnt = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == last) {
                cnt++;
            } else {
                cnt = 1;
            }
            if (cnt < 3) {
                nums[j++] = nums[i];
            }
            last = nums[i];
        }
        return j;
    }
};