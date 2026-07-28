class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int N = board.size();
        vector<unordered_set<char>> rows(9), cols(9), squares(9);

        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                char z = board[r][c];
                if (z == '.')
                    continue;
                int y = r / 3 * 3 + c / 3;
                if (rows[r].count(z) || cols[c].count(z) || squares[y].count(z))
                    return 0;
                rows[r].insert(z), cols[c].insert(z), squares[y].insert(z);
            }
        }

        return 1;
    }
};