class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size(), l = 0, r = n - 1;
        while (l < r) {
            int sum = nums[l] + nums[r];
            if (sum > target) 
                r--;
            else if (sum < target)
                l++;
            else
                return {l + 1, r + 1};
        }
        return {};
    }
};