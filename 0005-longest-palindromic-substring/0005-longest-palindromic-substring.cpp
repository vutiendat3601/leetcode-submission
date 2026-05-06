class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string ans = "";

        for (int i = 0; i < n; i++) {
            // Odd length
            int l = i, r = i;
            while (0 <= l && r < n && s[l] == s[r]) {
                int len = r - l + 1;
                if (len > ans.size()) {
                    ans = s.substr(l, len);
                }
                l--;
                r++;
            }

            // Even length
            l = i, r = i + 1;
            while (0 <= l && r < n && s[l] == s[r]) {
                int len = r - l + 1;
                if (len > ans.size()) {
                    ans = s.substr(l, len);
                }
                l--;
                r++;
            }
        }

        return ans;
    }
};

// Palindrome DP, time: O(n^2), space: O(1)