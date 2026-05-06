class Solution {
private:
    string s, p;
    int m, n;

    bool backtrack(int i, int j) {
        if (j >= n)
            return i >= m;
        char nxtChar = j + 1 < n ? p[j + 1] : '\0';
        if (nxtChar == '*') {
            int k = i;
            if (p[j] == '.') {
                while (k <= m) {
                    if (backtrack(k, j + 2))
                        return 1;
                    k++;
                }
            } else {
                if (backtrack(i, j + 2))
                    return 1;
                while (k < m && s[k] == p[0]) {
                    if (backtrack(k + 1, j + 2))
                        return 1;
                    k++;
                }
            }
        } else {
            if (i < m && (p[j] == s[i] || p[j] == '.'))
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