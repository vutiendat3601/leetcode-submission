class Solution {
private:
    set<vector<int>> ans;
    unordered_map<int, int> cnt;
    vector<int> ans_item;
    int n;

    void backtrack(vector<int>& nums, int i) {
        if (i >= n) {
            ans.insert(vector<int>(ans_item.begin(), ans_item.end()));
            return;
        }
        for (auto& [k, v] : cnt) {
            if (v > 0) {
                cnt[k]--;
                ans_item.push_back(k);
                backtrack(nums, i + 1);
                ans_item.pop_back();
                cnt[k]++;
            }
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        for (auto& num : nums)
            cnt[num]++;

        backtrack(nums, 0);
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};

// Backtracking