class Solution {
private:
    vector<string> ans;
    int n;
    string ans_item = "";

    void backtrack(int open, int close) {
        if (ans_item.size() == 2 * n) {
            ans.push_back(ans_item);
            return;
        }
        if (open < n) {
            ans_item += "(";
            backtrack(open + 1, close);
            ans_item.resize(ans_item.size() - 1);
        }
        if (close < open) {
            ans_item += ")";
            backtrack(open, close + 1);
            ans_item.resize(ans_item.size() - 1);
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        this->n = n;
        backtrack(0, 0);
        return ans;
    }
};

// Backtracking, time: O(2^n), space: O(2^n)