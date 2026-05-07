class Solution {
private:
    int n;
    vector<int> queen;

    int backtrack(int row) {
        if (row >= n)
            return 1;
        int ans = 0;
        for (int col = 0; col < n; col++) {
            bool available = 1;
            for (int r = 0; r < row; r++) {
                if (queen[r] == col || abs(col - queen[r]) == row - r) {
                    available = 0;
                    break;
                }
            }
            if (available) {
                queen[row] = col;
                ans += backtrack(row + 1);
                queen[row] = 0;
            }
        }
        return ans;
    }

public:
    int totalNQueens(int n) {
        this->n = n, queen = vector<int>(n);
        return backtrack(0);
    }
};

// Backtracking