class Solution {
private:
    string s, p;
    int m, n;

    bool backtrack(int i, int j) {
        if (j >= n)
            return i >= m;
        string tar = p.substr(j, 2);
        if (tar[tar.size() - 1] == '*') {
            int k = i;
            if (tar[0] == '.') {
                while (k <= m) {
                    if (backtrack(k, j + 2))
                        return 1;
                    k++;
                }
            } else {
                if (backtrack(i, j + 2))
                    return 1;
                while (k < m && s[k] == tar[0]) {
                    if (backtrack(k + 1, j + 2))
                        return 1;
                    k++;
                }
            }
        } else {
            if (i < m && (tar[0] == s[i] || tar[0] == '.'))
                return backtrack(i + 1, j + 1);
        }
        return 0;
    }

public:
    bool isMatch(string s, string p) {
        m = s.size(), n = p.size(), this->s = s, this->p = p;
        return backtrack(0, 0);
    }
};