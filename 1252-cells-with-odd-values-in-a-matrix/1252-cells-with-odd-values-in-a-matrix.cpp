class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<vector<int>> mt(m, vector<int>(n, 0));
        int ans = 0;
        for (auto indice : indices) {
            for (int c = 0; c < n; c++)
                mt[indice[0]][c]++;

            for (int r = 0; r < m; r++)
                mt[r][indice[1]]++;
        }

        for (vector<int> r : mt) {
            for (int c : r)
                if (c % 2)
                    ans++;
        }

        return ans;
    }
};