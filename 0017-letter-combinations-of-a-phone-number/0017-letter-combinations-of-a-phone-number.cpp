class Solution {
private:
    unordered_map<char, string> mp = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"},
                                      {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
                                      {'8', "tuv"}, {'9', "wxyz"}};
    vector<string> ans;
    string ans_item, digits;
    int n;

    void backtrack(int k) {
        if (k >= n) {
            ans.push_back(ans_item);
            return;
        }
        for (auto& c : mp[digits[k]]) {
            ans_item += c;
            backtrack(k + 1);
            ans_item.resize(ans_item.size() - 1);
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        this->digits = digits;
        n = digits.size();
        backtrack(0);
        return ans;
    }
};

// Backtracking