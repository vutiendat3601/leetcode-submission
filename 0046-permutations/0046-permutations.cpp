class Solution {
private:
    unordered_set<int> visited;
    vector<vector<int>> ans;
    vector<int> ans_item;
    int n;

    void backtrack(vector<int>& nums, int k) {
        if (k >= n) {
            ans.push_back(vector<int>(ans_item.begin(), ans_item.end()));
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!visited.count(i)) {
                visited.insert(i);
                ans_item.push_back(nums[i]);
                backtrack(nums, k + 1);
                ans_item.pop_back();
                visited.erase(i);
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        backtrack(nums, 0);
        return ans;
    }
};

// Backtracking