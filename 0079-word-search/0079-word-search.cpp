class Solution {
private:
    vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    bool backtrack(pair<int, int> pos, int k, vector<vector<char>>& board,
                   string word, vector<vector<bool>>& visited) {
        auto m = board.size(), n = board[0].size(), sz = word.size();
        if (k >= sz)
            return 1;
        auto [r, c] = pos;
        for (auto& [dr, dc] : DIRECTIONS) {
            int x = r + dr, y = c + dc;
            bool ok =
                x >= 0 && y >= 0 && x < m && y < n && board[x][y] == word[k];
            if (ok && !visited[x][y]) {
                visited[x][y] = 1;
                if (backtrack({x, y}, k + 1, board, word, visited))
                    return 1;
                visited[x][y] = 0;
            }
        }
        return 0;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, 0));
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                bool ok = board[r][c] == word[0];
                if (ok) {
                    visited[r][c] = 1;
                    if (backtrack({r, c}, 1, board, word, visited))
                        return 1;
                    visited[r][c] = 0;
                }
            }
        }
        return 0;
    }
};