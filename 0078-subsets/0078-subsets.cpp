class Solution {
private:
    vector<vector<int>> ans;
    vector<int> nums, ans_item;
    int n = 0;

    void backtrack(int i) {
        if (i >= n) {
            ans.push_back(ans_item);
            return;
        }
        backtrack(i + 1);
        ans_item.push_back(nums[i]);
        backtrack(i + 1);
        ans_item.pop_back();
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();
        backtrack(0);
        return ans;
    }
};