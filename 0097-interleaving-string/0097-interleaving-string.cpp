class Solution {
private:
    int n, n1, n2;
    string s, s1, s2;
    bool dfs(int i1, int i2, vector<vector<int>>& cache) {
        int k = i1 + i2;
        if (k >= n)
            return 1;
        if (i1 > n1 || i2 > n2)
            return 0;
        if (cache[i1][i2] < 0) {
            bool s1_check = i1 < n1 ? s[k] == s1[i1] : 0;
            bool s2_check = i2 < n2 ? s[k] == s2[i2] : 0;
            cache[i1][i2] = 0;
            if (s1_check && s2_check)
                cache[i1][i2] =
                    dfs(i1 + 1, i2, cache) || dfs(i1, i2 + 1, cache);
            else if (s1_check)
                cache[i1][i2] = dfs(i1 + 1, i2, cache);
            else if (s2_check)
                cache[i1][i2] = dfs(i1, i2 + 1, cache);
        }
        return cache[i1][i2];
    }

public:
    bool isInterleave(string s1, string s2, string s3) {
        n = s3.size(), n1 = s1.size(), n2 = s2.size();
        if (n1 + n2 != n)
            return 0;
        this->s1 = s1, this->s2 = s2, s = s3;
        vector<vector<int>> cache(n1 + 1, vector<int>(n2 + 1, -1));
        return dfs(0, 0, cache);
    }
};