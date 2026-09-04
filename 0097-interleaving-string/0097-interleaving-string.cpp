class Solution {
private:
    int m, n, p;
    string s1, s2, s3;
    bool dfs(int i, int j, vector<vector<int>>& cache) {
        int k = i + j;
        if (i >= m && j >= n)
            return k == p;
        if (cache[i][j] < 0) {
            bool cont1 = i < m ? s1[i] == s3[k] : 0;
            bool cont2 = j < n ? s2[j] == s3[k] : 0;
            cache[i][j] = 0;
            if (cont1)
                cache[i][j] = dfs(i + 1, j, cache);
            if (cont2)
                cache[i][j] = cache[i][j] || dfs(i, j + 1, cache);
        }
        return cache[i][j];
    }

public:
    bool isInterleave(string s1, string s2, string s3) {
        m = s1.size(), n = s2.size(), p = s3.size();
        this->s1 = s1, this->s2 = s2, this->s3 = s3;
        if (m + n != p)
            return 0;
        vector<vector<int>> cache(m + 1, vector<int>(n + 1, -1));
        return dfs(0, 0, cache);
    }
};