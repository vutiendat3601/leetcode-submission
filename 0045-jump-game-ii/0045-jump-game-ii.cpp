class Solution {
private:
    int n;
    int jump(vector<int>& nums, int posStart) {
        if (posStart + nums[posStart] >= n - 1)
            return 1;

        int max = -1, maxIndex = -1;
        for (int i = 1; i <= nums[posStart]; i++)
            if (posStart + i + nums[posStart + i] > max)
                max = posStart + i + nums[posStart + i],
                maxIndex = posStart + i;

        return jump(nums, maxIndex) + 1;
    }

public:
    int jump(vector<int>& nums) {
        n = nums.size();
        return n <= 1 ? 0 : jump(nums, 0);
    }
};