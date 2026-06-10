class Solution {
private:
    set<vector<int>> ans;
    vector<int> ans_item, nums;
    int n;

    void backtrack(int i) {
        if (i >= n) {
            ans.insert(vector<int>(ans_item.begin(), ans_item.end()));
            return;
        }
        ans_item.push_back(nums[i]);
        backtrack(i + 1);
        ans_item.pop_back();
        backtrack(i + 1);
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        this->nums = nums;
        this->n = nums.size();
        backtrack(0);
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};