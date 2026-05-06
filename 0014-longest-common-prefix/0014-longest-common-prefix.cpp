class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size(), k = -1;
        if (n == 1)
            return strs[0];

        string ans = "", pref = strs[0];
        bool cont = 1;
        while (cont) {
            k++;
            for (int i = 1; i < n; i++) {
                if (strs[i].size() <= k || strs[i][k] != pref[k]) {
                    cont = 0;
                    break;
                }
            }
        }

        return pref.substr(0, k);
    }
};