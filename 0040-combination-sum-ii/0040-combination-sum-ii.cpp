class Solution {
private:
    vector<vector<int>> ans;
    vector<int> ans_item;
    int n = 0;

    void backtrack(vector<int>& nums, int target, int i) {
        if (!target) {
            ans.push_back(ans_item);
            return;
        }
        int last = INT_MAX;
        for (int k = i; k < n; k++) {
            if (last != nums[k] && target - nums[k] >= 0) {
                ans_item.push_back(nums[k]);
                backtrack(nums, target - nums[k], k + 1);
                ans_item.pop_back();
            }
            last = nums[k];
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        n = nums.size();
        backtrack(nums, target, 0);
        return ans;
    }
};

// Backtracking