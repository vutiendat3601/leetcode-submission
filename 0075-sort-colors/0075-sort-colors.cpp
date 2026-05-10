class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size(), z = 0, tmp = 0;
        for (int i = 0; i < 2; i++)
            for (int j = z; j < n; j++)
                if (nums[j] == i)
                    tmp = nums[j], nums[j] = nums[z], nums[z++] = tmp;
    }
};