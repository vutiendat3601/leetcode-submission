class Solution {
private:
    vector<vector<string>> ans;
    vector<int> queens;
    int n;

    void backtrack(int row) {
        if (row == n) {
            vector<string> new_result;
            for (int pos : queens) {
                string result_str = "";
                for (int i = 0; i < n; i++)
                    result_str += i == pos ? "Q" : ".";
                new_result.push_back(result_str);
            }
            ans.push_back(new_result);
        }
        for (int col = 0; col < n; col++) {
            int last_row = row - 1;
            bool available = 1;
            while (last_row >= 0) {
                if (queens[last_row] == col ||
                    abs(col - queens[last_row]) == row - last_row) {
                    available = 0;
                    break;
                }
                last_row--;
            }
            if (available) {
                queens[row] = col;
                backtrack(row + 1);
                queens[row] = 0;
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        queens = vector<int>(n);
        backtrack(0);
        return ans;
    }
};

// Backtracking