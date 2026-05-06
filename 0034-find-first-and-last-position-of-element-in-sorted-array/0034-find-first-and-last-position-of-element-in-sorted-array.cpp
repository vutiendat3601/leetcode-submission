class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size(), i = 0;
        vector<int> ans = {-1, -1};

        while (i < n) {
            if (nums[i] == target) {
                ans[0] = ans[1] = i;
                break;
            }
            i++;
        }
        for (int j = n - 1; j > i; j--) {
            if (nums[j] == target) {
                ans[1] = j;
                break;
            }
        }
        return ans;
    }
};

// Brute Force, time: O(n), space: O(1)