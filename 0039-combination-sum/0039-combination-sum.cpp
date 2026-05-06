class Solution {
private:
    vector<vector<int>> ans;
    vector<int> ans_item;
    int n;
    void backtrack(vector<int>& nums, int target, int i) {
        if (!target) {
            ans.push_back(ans_item);
            return;
        }
        for (int k = i; k < n; k++) {
            if (target - nums[k] >= 0) {
                ans_item.push_back(nums[k]);
                backtrack(nums, target - nums[k], k);
                ans_item.pop_back();
            }
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        n = nums.size();
        backtrack(nums, target, 0);
        return ans;
    }
};