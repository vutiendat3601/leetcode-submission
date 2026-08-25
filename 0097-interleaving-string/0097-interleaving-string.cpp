class Solution {
private:
    int n, n1, n2;
    string s, s1, s2;
    bool dfs(int k, int i1, int i2, unordered_map<string, bool>& cache) {
        if (k >= n)
            return 1;
        string key = to_string(k) + "_" + to_string(i1) + "_" + to_string(i2);
        if (!cache.count(key)) {
            bool s1_check = i1 < n1 ? s[k] == s1[i1] : 0;
            bool s2_check = i2 < n2 ? s[k] == s2[i2] : 0;
            if (s1_check)
                cache[key] = dfs(k + 1, i1 + 1, i2, cache);
            if (s2_check && !cache[key])
                cache[key] = dfs(k + 1, i1, i2 + 1, cache);
        }
        return cache[key];
    }

public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size())
            return 0;
        n = s3.size(), n1 = s1.size(), n2 = s2.size();
        this->s1 = s1, this->s2 = s2, s = s3;
        unordered_map<string, bool> cache;
        return dfs(0, 0, 0, cache);
    }
};