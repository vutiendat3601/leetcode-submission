class Solution {
private:
    int n, target;
    int dfs(int k, int sum, vector<int>& nums) {
        if (k >= n)
            return sum == target ? 1 : 0;
        return dfs(k + 1, sum + nums[k], nums) +
               dfs(k + 1, sum - nums[k], nums);
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size(), this->target = target;
        return dfs(0, 0, nums);
    }
};