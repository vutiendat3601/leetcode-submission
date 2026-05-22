class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size(), k = -1;
        for (int step = n; step >= 1; step /= 2)
            while (k + step < n && nums[k + step] > nums[0])
                k += step;

        while (k + 1 < n && nums[k + 1] >= nums[0])
            k++;

        return k + 1 < n ? nums[k + 1] : nums[0];
    }
};