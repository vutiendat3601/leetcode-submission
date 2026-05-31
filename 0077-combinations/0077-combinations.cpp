class Solution {
private:
    void backtrack(int n, int k, int i, vector<int>& ans_item,
                   vector<vector<int>>& ans) {
        if (i >= k) {
            ans.push_back(ans_item);
            return;
        }
        auto sz = ans_item.size();
        for (int j = sz ? ans_item[sz - 1] + 1 : 1; j <= n; j++) {
            ans_item.push_back(j);
            backtrack(n, k, i + 1, ans_item, ans);
            ans_item.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> ans_item;
        backtrack(n, k, 0, ans_item, ans);
        return ans;
    }
};