class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), last = INT_MIN, i = 0, j = 0, ans = 0;

        while (j < n) {
            if (last != nums[j])
                nums[i++] = nums[j], ans++;
            last = nums[j], j++;
        }

        return ans;
    }
};

// 2-pointers, time: O(n), space: O(1)