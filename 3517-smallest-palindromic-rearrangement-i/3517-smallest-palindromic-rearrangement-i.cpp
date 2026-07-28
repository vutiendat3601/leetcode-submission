class Solution {
public:
    string smallestPalindrome(string s) {
        unordered_map<char, int> cnts;
        for (auto& c : s)
            cnts[c]++;
        int n = s.size(), l = 0, r = n - 1;
        string ans(n, '1');
        char last = '1';
        for (char c = 'a'; c <= 'z'; c++) {
            while (cnts[c] > 1)
                ans[l++] = ans[r--] = c, cnts[c] -= 2;
            if (cnts[c])
                last = c;
        }
        if (n & 1)
            ans[l] = last;
        return ans;
    }
};