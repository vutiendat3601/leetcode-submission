class Solution {
private:
    string s, p;
    int m, n;

    bool backtrack(int i, int j, unordered_map<string, bool>& cache) {
        if (j >= n)
            return i >= m;
        string key = to_string(i) + "," + to_string(j);
        if (!cache.count(key)) {
            cache[key] = 0;
            if ((j + 1 < n ? p[j + 1] : '\0') == '*') {
                int k = i;
                if (p[j] == '.') {
                    while (k <= m) {
                        if (backtrack(k, j + 2, cache)) {
                            cache[key] = 1;
                            break;
                        }
                        k++;
                    }
                } else {
                    if (backtrack(i, j + 2, cache)) {
                        cache[key] = 1;
                    } else {
                        while (k < m && s[k] == p[j]) {
                            if (backtrack(k + 1, j + 2, cache)) {
                                cache[key] = 1;
                                break;
                            }
                            k++;
                        }
                    }
                }
            } else {
                if (i < m && (p[j] == s[i] || p[j] == '.'))
                    cache[key] = backtrack(i + 1, j + 1, cache);
            }
        }
        return cache[key];
    }

public:
    bool isMatch(string s, string p) {
        m = s.size(), n = p.size(), this->s = s, this->p = p;
        unordered_map<string, bool> cache;
        return backtrack(0, 0, cache);
    }
};