class Solution {
private:
    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), i = n - 1;
        bool is_changed = 0;
        while (i > 0) {
            if (nums[i] > nums[i - 1]) {
                int j = n - 1;
                while (nums[i - 1] >= nums[j]) {
                    j--;
                }
                swap(nums, i - 1, j);
                for (j = 0; j < (n - i) / 2; j++) {
                    swap(nums, i + j, n - 1 - j);
                }
                i = n - 1;
                is_changed = 1;
                break;
            }
            i--;
        }
        if (!is_changed)
            sort(nums.begin(), nums.end());
    }
};