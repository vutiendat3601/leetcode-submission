class Solution {
private:
    const int N = 9;

public:
    bool isValidSudoku(vector<vector<char>>& b) {
        vector<unordered_set<char>> cols(N), rows(N), area(N);
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                if (isdigit(b[r][c])) {
                    // check column
                    if (cols[c].count(b[r][c]))
                        return 0;

                    // Check row
                    if (rows[r].count(b[r][c]))
                        return 0;

                    // Check area box
                    int k = (r / 3) * 3 + c / 3;
                    if (area[k].count(b[r][c]))
                        return 0;

                    rows[r].insert(b[r][c]), cols[c].insert(b[r][c]),
                        area[k].insert(b[r][c]);
                }
            }
        }
        return 1;
    }
};

// Hashing, time: O(n^2), space: O(n^3)